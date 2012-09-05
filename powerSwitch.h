/*
 * powerSwitchGui.h
 * This file is part of powerSwitchGui
 *
 * Copyright (C) 2006 - Krzysiek Szczuka
 *
 * powerSwitchGui is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * powerSwitchGui is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with powerSwitchGui; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, 
 * Boston, MA  02110-1301  USA
 */


#ifndef _POWERSWITCH_GUI
#define _POWERSWITCH_GUI

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <usb.h>



#define USBDEV_SHARED_VENDOR    0x16C0	/* VOTI */
#define USBDEV_SHARED_PRODUCT   0x05DC	/* Obdev's free shared PID */
/* Use obdev's generic shared VID/PID pair and follow the rules outlined
 * in firmware/usbdrv/USBID-License.txt.
 */

#define PSG_ACTIVE(v) (!v)
// definition for quick change of active state, because on my EvBoard active 
// is zero..


#define PSCMD_ECHO  0
#define PSCMD_GET   1
#define PSCMD_ON    2
#define PSCMD_OFF   3
/* These are the vendor specific SETUP commands implemented by our USB device */

#define USB_ERROR_NOTFOUND  1
#define USB_ERROR_ACCESS    2
#define USB_ERROR_IO        3


extern usb_dev_handle *handle;
extern unsigned char buffer[8];
extern int nBytes;



int usbGetStringAscii (usb_dev_handle * dev, int index, int langid,
					   char *buf, int buflen);


int usbOpenDevice (usb_dev_handle ** device, int vendor, char *vendorName,
				   int product, char *productName);


void usbSend (int pscmd, int duration, int port);


void usbUpdate (void);


void usbTest (void);


#endif
