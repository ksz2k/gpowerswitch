/*
 * main.c
 * This file is part of gPowerSwitch
 *
 * gPowerSwitch is GTK+2.0 based frontend for OBDEV's PowerSwitch.
 *  More info about PowerSwitch at: 
 *  http://www.obdev.at/products/avrusb/index.html
 *
 * Copyright (C) 2006 - Krzysiek Szczuka <kszczuka@gmail.com>
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



#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <usb.h>				/* this is libusb, see http://libusb.sourceforge.net/ */
#include <gtk/gtk.h>
#include <glade/glade-xml.h>

#include "powerSwitch.h"
#include "psg-messages.h"
#include "psg-callbacks.h"

usb_dev_handle *handle = NULL;
unsigned char buffer[8];
int nBytes;


GladeXML *xml = NULL;



static void
update_toggles (GtkWidget * dialog)
{
	usbUpdate ();
	
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
								  (glade_xml_get_widget (xml, "c0")),
								  ((buffer[0] & (1 << 0)) ?
								   PSG_ACTIVE (TRUE)
								   : PSG_ACTIVE (FALSE)));
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
								  (glade_xml_get_widget (xml, "c1")),
								  ((buffer[0] & (1 << 1)) ?
								   PSG_ACTIVE (TRUE)
								   : PSG_ACTIVE (FALSE)));
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
								  (glade_xml_get_widget (xml, "c2")),
								  ((buffer[0] & (1 << 2)) ?
								   PSG_ACTIVE (TRUE)
								   : PSG_ACTIVE (FALSE)));
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
								  (glade_xml_get_widget (xml, "c3")),
								  ((buffer[0] & (1 << 3)) ?
								   PSG_ACTIVE (TRUE)
								   : PSG_ACTIVE (FALSE)));
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
								  (glade_xml_get_widget (xml, "c4")),
								  ((buffer[0] & (1 << 4)) ?
								   PSG_ACTIVE (TRUE)
								   : PSG_ACTIVE (FALSE)));
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
								  (glade_xml_get_widget (xml, "c5")),
								  ((buffer[0] & (1 << 5)) ?
								   PSG_ACTIVE (TRUE)
								   : PSG_ACTIVE (FALSE)));
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
								  (glade_xml_get_widget (xml, "c6")),
								  ((buffer[0] & (1 << 6)) ?
								   PSG_ACTIVE (TRUE)
								   : PSG_ACTIVE (FALSE)));
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
								  (glade_xml_get_widget (xml, "c7")),
								  ((buffer[0] & (1 << 7)) ?
								   PSG_ACTIVE (TRUE)
								   : PSG_ACTIVE (FALSE)));
}


#ifdef G_OS_WIN32
gchar *package_prefix;
gchar *package_datadir;
#endif


int
main (int argc, char *argv[])
{
	GtkWidget *dialog = NULL;
#ifdef G_OS_WIN32
	gchar *temp;

	package_prefix =
		g_win32_get_package_installation_directory (NULL, NULL);
	package_datadir = g_strdup_printf ("%s%s", package_prefix, "/share");
#endif

#ifdef ENABLE_NLS
#ifdef G_OS_WIN32
	temp = g_strdup_printf ("%s%s", package_prefix, "/lib/locale");
	bindtextdomain (GETTEXT_PACKAGE, temp);
	g_free (temp);
#else
	bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
#endif
	bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
	textdomain (GETTEXT_PACKAGE);
#endif
	
	gtk_set_locale ();
	gtk_init (&argc, &argv);
	
#ifdef G_OS_WIN32
	temp = g_strdup_printf ("%s%s", package_datadir, "/pixmaps");
	//add_pixmap_directory (temp);
	g_free (temp);
#else
	//add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");
#endif

	//dialog = create_dialog ();
	xml = glade_xml_new (GLADE_FILE, NULL, NULL);
	if( !xml ) {
	#ifdef G_OS_WIN32
		g_free (package_prefix);
		g_free (package_datadir);
	#endif
		return 1;
	}
	connect_signals ();
	dialog = glade_xml_get_widget (xml, "dialog");
	
	gtk_window_set_title (GTK_WINDOW (dialog), PACKAGE " v" VERSION);

	usb_init ();
	if (usbOpenDevice
		(&handle, USBDEV_SHARED_VENDOR, /*NULL */USBDEV_VENDOR_NAME  ,
		 USBDEV_SHARED_PRODUCT, /*NULL */ USBDEV_NAME ) != 0) {
		psg_message_dialog (GTK_MESSAGE_WARNING,
		//fprintf (stderr,
				 "Could not find USB device \"%s\" with vid=0x%x pid=0x%x\n",
				 USBDEV_NAME, USBDEV_SHARED_VENDOR, USBDEV_SHARED_PRODUCT);
		//exit (1);
	}
// We have searched all devices on all busses for our USB device above. Now
// try to open it and perform the vendor specific control operations for the
// function requested by the user.


	gtk_widget_show (dialog);
	update_toggles (dialog);

	gtk_main ();
	usb_close (handle);
#ifdef G_OS_WIN32
	g_free (package_prefix);
	g_free (package_datadir);
#endif
	return 0;
}

/*

int main(int argc, char **argv)
{

    if(strcmp(argv[1], "test") == 0){
        int i, v, r;
// The test consists of writing 1000 random numbers to the device and checking
// the echo. This should discover systematic bit errors (e.g. in bit stuffing).
 
        for(i=0;i<1000;i++){
            v = rand() & 0xffff;
            nBytes = usb_control_msg(handle, USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_ENDPOINT_IN, PSCMD_ECHO, v, 0, (char *)buffer, sizeof(buffer), 5000);
            if(nBytes < 2){
                if(nBytes < 0)
                    fprintf(stderr, "USB error: %s\n", usb_strerror());
                fprintf(stderr, "only %d bytes received in iteration %d\n", nBytes, i);
                exit(1);
            }
            r = buffer[0] | (buffer[1] << 8);
            if(r != v){
                fprintf(stderr, "data error: received 0x%x instead of 0x%x in iteration %d\n", r, v, i);
                exit(1);
            }
        }
        printf("test succeeded\n");
    }else if(strcmp(argv[1], "status") == 0){
        int i;
        nBytes = usb_control_msg(handle, USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_ENDPOINT_IN, PSCMD_GET, 0, 0, (char *)buffer, sizeof(buffer), 5000);
        if(nBytes < 2){
            if(nBytes < 0)
                fprintf(stderr, "USB error: %s\n", usb_strerror());
            fprintf(stderr, "only %d bytes status received\n", nBytes);
            exit(1);
        }
        for(i=0;i<8;i++){
            int isOn = buffer[0] & (1 << i);
            int isInv = buffer[1] & (1 << i);
            printf("port %d: %s%s\n", i, isOn ? "on" : "off", isInv ? (isOn ? " / pulse off" : " / pulse on") : "");
        }
    }else{
        int port, duration = 0;
        if(argc < 3){
            usage(argv[0]);
            exit(1);
        }
        port = atoi(argv[2]);
        if(argc > 3){
            if((duration = (int)(atof(argv[3]) / 0.2 + 0.5)) > 255)
                duration = 255;
        }
        if(strcmp(argv[1], "on") == 0){
            nBytes = usb_control_msg(handle, USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_ENDPOINT_IN, PSCMD_ON, duration, port, (char *)buffer, sizeof(buffer), 5000);
        }else if(strcmp(argv[1], "off") == 0){
            nBytes = usb_control_msg(handle, USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_ENDPOINT_IN, PSCMD_OFF, duration, port, (char *)buffer, sizeof(buffer), 5000);
        }else{
            nBytes = 0;
            usage(argv[0]);
            exit(1);
        }
        if(nBytes < 0)
            fprintf(stderr, "USB error: %s\n", usb_strerror());
    }
    usb_close(handle);
    return 0;
}
*/
