/*
 * psg-messages.c
 * This file is part of gPowreSwitch
 *
 * Copyright (C) 2006, 2007 - Krzysiek Szczuka
 *
 * gPowreSwitch is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * gPowreSwitch is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with gPowreSwitch; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, 
 * Boston, MA  02110-1301  USA
 */
 
 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

#include "psg-messages.h"
#include "powerSwitch.h"
//#include "support.h"



GtkWidget *
psg_message_dialog (GtkMessageType type, gchar * format, ...)
{

	va_list args;
	gchar *msg;

	g_return_val_if_fail (format != NULL, NULL);

	va_start (args, format);
	msg = g_strdup_vprintf (format, args);
	va_end (args);

	GtkWidget *dialog;

	dialog =
		gtk_message_dialog_new (NULL,
								GTK_DIALOG_MODAL |
								GTK_DIALOG_DESTROY_WITH_PARENT, type,
								GTK_BUTTONS_OK, msg);
	gtk_dialog_run (GTK_DIALOG (dialog));
	gtk_widget_destroy (dialog);
	g_free (msg);
	return dialog;
}
