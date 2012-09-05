/*
 * powerSwitchGui.c
 * This file is part of gPowerSwitch
 *
 * Copyright (C) 2006 - Krzysiek Szczuka
 *
 * gPowerSwitch is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * gPowerSwitch is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with gPowerSwitch; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, 
 * Boston, MA  02110-1301  USA
 */



/*
	General Description:
	This program controls the PowerSwitch USB device using GTK+ GUI.
	It must be linked with libusb, a library for accessing the USB bus from
	Linux, FreeBSD, Mac OS X and other Unix operating systems. Libusb can be
	obtained from http://libusb.sourceforge.net/. Also it must be linked with
	GTK+ >= 2.0.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <usb.h>				/* this is libusb, see http://libusb.sourceforge.net/ */
#include <gtk/gtk.h>

#include "powerSwitch.h"
//#include "support.h"
#include "psg-messages.h"


int
usbGetStringAscii (usb_dev_handle * dev, int index, int langid, char *buf,
				   int buflen)
{
	char buffer[256];
	int rval, i;

	if ((rval =
		 usb_control_msg (dev, USB_ENDPOINT_IN, USB_REQ_GET_DESCRIPTOR,
						  (USB_DT_STRING << 8) + index, langid, buffer,
						  sizeof (buffer), 1000)) < 0)
		return rval;
	if (buffer[1] != USB_DT_STRING)
		return 0;
	if ((unsigned char) buffer[0] < rval)
		rval = (unsigned char) buffer[0];
	rval /= 2;
	/* lossy conversion to ISO Latin1 */
	for (i = 1; i < rval; i++) {
		if (i > buflen)			/* destination buffer overflow */
			break;
		buf[i - 1] = buffer[2 * i];
		if (buffer[2 * i + 1] != 0)	/* outside of ISO Latin1 range */
			buf[i - 1] = '?';
	}
	buf[i - 1] = 0;
	return i - 1;
}


/* PowerSwitch uses the free shared default VID/PID. If you want to see an
 * example device lookup where an individually reserved PID is used, see our
 * RemoteSensor reference implementation.
 */


int
usbOpenDevice (usb_dev_handle ** device, int vendor, char *vendorName,
			   int product, char *productName)
{
	struct usb_bus *bus;
	struct usb_device *dev;
	usb_dev_handle *handle = NULL;
	int errorCode = USB_ERROR_NOTFOUND;
	static int didUsbInit = 0;

	if (!didUsbInit) {
		didUsbInit = 1;
		usb_init ();
	}
	usb_find_busses ();
	usb_find_devices ();
	for (bus = usb_get_busses (); bus; bus = bus->next) {
		for (dev = bus->devices; dev; dev = dev->next) {
			if (dev->descriptor.idVendor == vendor
				&& dev->descriptor.idProduct == product) {
				char string[256];
				int len;

				handle = usb_open (dev);	/* we need to open the device in order to query strings */
				if (!handle) {
					errorCode = USB_ERROR_ACCESS;
					fprintf (stderr,
							 "Warning: cannot open USB device: %s\n",
							 usb_strerror ());
					continue;
				}
				if (vendorName == NULL && productName == NULL) {	/* name does not matter */
					break;
				}
				/* now check whether the names match: */
				len =
					usbGetStringAscii (handle,
									   dev->descriptor.iManufacturer,
									   0x0409, string, sizeof (string));
				if (len < 0) {
					errorCode = USB_ERROR_IO;
					fprintf (stderr,
							 "Warning: cannot query manufacturer for device: %s\n",
							 usb_strerror ());
				} else {
					errorCode = USB_ERROR_NOTFOUND;
					/* fprintf(stderr, "seen device from vendor ->%s<-\n", string); */
					if (strcmp (string, vendorName) == 0) {
						len =
							usbGetStringAscii (handle,
											   dev->descriptor.iProduct,
											   0x0409, string,
											   sizeof (string));
						if (len < 0) {
							errorCode = USB_ERROR_IO;
							fprintf (stderr,
									 "Warning: cannot query product for device: %s\n",
									 usb_strerror ());
						} else {
							errorCode = USB_ERROR_NOTFOUND;
							/* fprintf(stderr, "seen product ->%s<-\n", string); */
							if (strcmp (string, productName) == 0)
								break;
						}
					}
				}
				usb_close (handle);
				handle = NULL;
			}
		}
		if (handle)
			break;
	}
	if (handle != NULL) {
		errorCode = 0;
		*device = handle;
	}
	return errorCode;
}


void
usbSend (int pscmd, int duration, int port)
{
	if( !handle )
		return;
	
	int duration2 = duration / 0.2 + 0.5;

	if (duration2 > 255)
		duration2 = 255;

	nBytes =
		usb_control_msg (handle,
						 USB_TYPE_VENDOR | USB_RECIP_DEVICE |
						 USB_ENDPOINT_IN, pscmd, duration2, port,
						 (char *) buffer, sizeof (buffer), 5000);
}


void
usbUpdate (void)
{
	if( !handle )
		return;
	
	nBytes =
		usb_control_msg (handle,
						 USB_TYPE_VENDOR | USB_RECIP_DEVICE |
						 USB_ENDPOINT_IN, PSCMD_GET, 0, 0,
						 (char *) buffer, sizeof (buffer), 5000);

	if (nBytes < 2) {
		if (nBytes < 0) {
			psg_message_dialog (GTK_MESSAGE_ERROR, "USB error: %s\n",
								usb_strerror ());
			gtk_exit (1);
		}
		fprintf (stderr, "only %d bytes status received\n", nBytes);
	}
}

void
usbTest (void)
{
	if( !handle )
		return;
	
	int i, v, r;

// The test consists of writing 1000 random numbers to the device and checking
// the echo. This should discover systematic bit errors (e.g. in bit stuffing).

	for (i = 0; i < 1000; i++) {
		v = rand () & 0xffff;
		nBytes =
			usb_control_msg (handle,
							 USB_TYPE_VENDOR | USB_RECIP_DEVICE |
							 USB_ENDPOINT_IN, PSCMD_ECHO, v, 0,
							 (char *) buffer, sizeof (buffer), 5000);
		if (nBytes < 2) {
			if (nBytes < 0) {
				fprintf (stderr, "USB error: %s\n", usb_strerror ());
				gtk_exit (1);
			}
			fprintf (stderr, "only %d bytes received in iteration %d\n",
					 nBytes, i);
		}
		r = buffer[0] | (buffer[1] << 8);
		if (r != v) {
			fprintf (stderr,
					 "data error: received 0x%x instead of 0x%x in iteration %d\n",
					 r, v, i);
		}
	}
	printf ("test succeeded\n");
}
