/*
 * psg-callback.c
 * This file is part of gPowerSwitch
 *
 * Copyright (C) 2007 - Krzysiek Szczuka
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

#include <gtk/gtk.h>
#include <glade/glade-xml.h>

//#include "callbacks.h"
#include "powerSwitch.h"

extern GladeXML *xml;





void
on_c0_toggled (void)
{
	if (PSG_ACTIVE (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON
					 (glade_xml_get_widget (xml,"c0"))))) {
		usbSend (PSCMD_ON, 0, 0);
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
									  (glade_xml_get_widget (xml,
										"con0")), TRUE);
	} else {
		usbSend (PSCMD_OFF, 0, 0);
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
									  (glade_xml_get_widget (xml,
										"con0")), FALSE);
	}
}


void
on_c1_toggled (void)
{
	if (PSG_ACTIVE (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON
					(glade_xml_get_widget (xml,"c1"))))) {
		usbSend (PSCMD_ON, 0, 1);
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
									  (glade_xml_get_widget (xml,
										"con1")), TRUE);
	} else {
		usbSend (PSCMD_OFF, 0, 1);
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
									  (glade_xml_get_widget (xml,
										"con1")), FALSE);
	}
}


void
on_c2_toggled (void)
{
	if (PSG_ACTIVE (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON
					(glade_xml_get_widget (xml,"c2"))))) {
		usbSend (PSCMD_ON, 0, 2);
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
									  (glade_xml_get_widget (xml,
										"con2")), TRUE);
	} else {
		usbSend (PSCMD_OFF, 0, 2);
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
									  (glade_xml_get_widget (xml,
										"con2")), FALSE);
	}
}


void
on_c3_toggled (void)
{
	if (PSG_ACTIVE (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON
					(glade_xml_get_widget (xml,"c3"))))) {
		usbSend (PSCMD_ON, 0, 3);
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
									  (glade_xml_get_widget (xml,
										"con3")), TRUE);
	} else {
		usbSend (PSCMD_OFF, 0, 3);
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
									  (glade_xml_get_widget (xml,
										"con3")), FALSE);
	}
}


void
on_c4_toggled (void)
{
	if (PSG_ACTIVE (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON
					(glade_xml_get_widget (xml,"c4"))))) {
		usbSend (PSCMD_ON, 0, 4);
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
									  (glade_xml_get_widget (xml,
										"con4")), TRUE);
	} else {
		usbSend (PSCMD_OFF, 0, 4);
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
									  (glade_xml_get_widget (xml,
										"con4")), FALSE);
	}
}


void
on_c5_toggled (void)
{
	if (PSG_ACTIVE (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON
					(glade_xml_get_widget (xml,"c5"))))) {
		usbSend (PSCMD_ON, 0, 5);
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
									  (glade_xml_get_widget (xml,
										"con5")), TRUE);
	} else {
		usbSend (PSCMD_OFF, 0, 5);
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
									  (glade_xml_get_widget (xml,
										"con5")), FALSE);
	}
}


void
on_c6_toggled (void)
{
	if (PSG_ACTIVE (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON
					(glade_xml_get_widget (xml,"c6"))))) {
		usbSend (PSCMD_ON, 0, 6);
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
									  (glade_xml_get_widget (xml,
										"con6")), TRUE);
	} else {
		usbSend (PSCMD_OFF, 0, 6);
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
									  (glade_xml_get_widget (xml,
										"con6")), FALSE);
	}
}


void
on_c7_toggled (void)
{
	if (PSG_ACTIVE (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON
					(glade_xml_get_widget (xml,"c7"))))) {
		usbSend (PSCMD_ON, 0, 7);
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
									  (glade_xml_get_widget (xml,
										"con7")), TRUE);
	} else {
		usbSend (PSCMD_OFF, 0, 7);
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
									  (glade_xml_get_widget (xml,
										"con7")), FALSE);
	}
}


void
on_closebutton_clicked (void)
{
	gtk_exit (0);
}


void
on_all_on_clicked (void)
{
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
								  (glade_xml_get_widget (xml, "c0")), TRUE);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
								  (glade_xml_get_widget (xml, "c1")), TRUE);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
								  (glade_xml_get_widget (xml, "c2")), TRUE);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
								  (glade_xml_get_widget (xml, "c3")), TRUE);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
								  (glade_xml_get_widget (xml, "c4")), TRUE);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
								  (glade_xml_get_widget (xml, "c5")), TRUE);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
								  (glade_xml_get_widget (xml, "c6")), TRUE);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
								  (glade_xml_get_widget (xml, "c7")), TRUE);
}


void
on_all_off_clicked (void)
{
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
								  (glade_xml_get_widget (xml, "c0")), FALSE);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
								  (glade_xml_get_widget (xml, "c1")), FALSE);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
								  (glade_xml_get_widget (xml, "c2")), FALSE);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
								  (glade_xml_get_widget (xml, "c3")), FALSE);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
								  (glade_xml_get_widget (xml, "c4")), FALSE);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
								  (glade_xml_get_widget (xml, "c5")), FALSE);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
								  (glade_xml_get_widget (xml, "c6")), FALSE);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
								  (glade_xml_get_widget (xml, "c7")), FALSE);
}




void
on_bt_send_clicked (void)
{

	if ((gtk_toggle_button_get_active
		 (GTK_TOGGLE_BUTTON (glade_xml_get_widget (xml, "ct0")))))
		usbSend ((PSG_ACTIVE
				  (gtk_toggle_button_get_active
				   (GTK_TOGGLE_BUTTON (glade_xml_get_widget (xml, "con0")))) ?
				  PSCMD_ON : PSCMD_OFF),
				 gtk_spin_button_get_value (GTK_SPIN_BUTTON
												   (glade_xml_get_widget (xml, "st0"))), 0);
	if ((gtk_toggle_button_get_active
		 (GTK_TOGGLE_BUTTON (glade_xml_get_widget (xml, "ct1")))))
		usbSend ((PSG_ACTIVE
				  (gtk_toggle_button_get_active
				   (GTK_TOGGLE_BUTTON (glade_xml_get_widget (xml, "con1")))) ?
				  PSCMD_ON : PSCMD_OFF),
				 gtk_spin_button_get_value (GTK_SPIN_BUTTON
												   (glade_xml_get_widget (xml, "st1"))), 1);
	if ((gtk_toggle_button_get_active
		 (GTK_TOGGLE_BUTTON (glade_xml_get_widget (xml, "ct2")))))
		usbSend ((PSG_ACTIVE
				  (gtk_toggle_button_get_active
				   (GTK_TOGGLE_BUTTON (glade_xml_get_widget (xml, "con2")))) ?
				  PSCMD_ON : PSCMD_OFF),
				 gtk_spin_button_get_value (GTK_SPIN_BUTTON
												   (glade_xml_get_widget (xml, "st2"))), 2);
	if ((gtk_toggle_button_get_active
		 (GTK_TOGGLE_BUTTON (glade_xml_get_widget (xml, "ct3")))))
		usbSend ((PSG_ACTIVE
				  (gtk_toggle_button_get_active
				   (GTK_TOGGLE_BUTTON (glade_xml_get_widget (xml, "con3")))) ?
				  PSCMD_ON : PSCMD_OFF),
				 gtk_spin_button_get_value (GTK_SPIN_BUTTON
												   (glade_xml_get_widget (xml, "st3"))), 3);
	if ((gtk_toggle_button_get_active
		 (GTK_TOGGLE_BUTTON (glade_xml_get_widget (xml, "ct4")))))
		usbSend ((PSG_ACTIVE
				  (gtk_toggle_button_get_active
				   (GTK_TOGGLE_BUTTON (glade_xml_get_widget (xml, "con4")))) ?
				  PSCMD_ON : PSCMD_OFF),
				 gtk_spin_button_get_value (GTK_SPIN_BUTTON
												   (glade_xml_get_widget (xml, "st4"))), 4);
	if ((gtk_toggle_button_get_active
		 (GTK_TOGGLE_BUTTON (glade_xml_get_widget (xml, "ct5")))))
		usbSend ((PSG_ACTIVE
				  (gtk_toggle_button_get_active
				   (GTK_TOGGLE_BUTTON (glade_xml_get_widget (xml, "con5")))) ?
				  PSCMD_ON : PSCMD_OFF),
				 gtk_spin_button_get_value (GTK_SPIN_BUTTON
												   (glade_xml_get_widget (xml, "st5"))), 5);
	if ((gtk_toggle_button_get_active
		 (GTK_TOGGLE_BUTTON (glade_xml_get_widget (xml, "ct6")))))
		usbSend ((PSG_ACTIVE
				  (gtk_toggle_button_get_active
				   (GTK_TOGGLE_BUTTON (glade_xml_get_widget (xml, "con6")))) ?
				  PSCMD_ON : PSCMD_OFF),
				 gtk_spin_button_get_value (GTK_SPIN_BUTTON
												   (glade_xml_get_widget (xml, "st6"))), 6);
	if ((gtk_toggle_button_get_active
		 (GTK_TOGGLE_BUTTON (glade_xml_get_widget (xml, "ct7")))))
		usbSend ((PSG_ACTIVE
				  (gtk_toggle_button_get_active
				   (GTK_TOGGLE_BUTTON (glade_xml_get_widget (xml, "con7")))) ?
				  PSCMD_ON : PSCMD_OFF),
				 gtk_spin_button_get_value (GTK_SPIN_BUTTON
												   (glade_xml_get_widget (xml, "st7"))), 7);
}


void
on_st0_value_changed (void)
{
	if (gtk_spin_button_get_value (GTK_SPIN_BUTTON
								   (glade_xml_get_widget (xml,"st0"))) > 0)
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
									  (glade_xml_get_widget (xml, "ct0")),
									  TRUE);
	else
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
									  (glade_xml_get_widget (xml, "ct0")),
									  FALSE);

	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
								  (glade_xml_get_widget (xml, "con0")),
								  !gtk_toggle_button_get_active
								  (GTK_TOGGLE_BUTTON
								   (glade_xml_get_widget (xml, "c0"))));
}


void
on_st1_value_changed (void)
{
	if (gtk_spin_button_get_value (GTK_SPIN_BUTTON
								   (glade_xml_get_widget (xml,"st1"))) > 0)
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
									  (glade_xml_get_widget (xml, "ct1")),
									  TRUE);
	else
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
									  (glade_xml_get_widget (xml, "ct1")),
									  FALSE);

	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
								  (glade_xml_get_widget (xml, "con1")),
								  !gtk_toggle_button_get_active
								  (GTK_TOGGLE_BUTTON
								   (glade_xml_get_widget (xml, "c1"))));
}


void
on_st2_value_changed (void)
{
	if (gtk_spin_button_get_value (GTK_SPIN_BUTTON
								   (glade_xml_get_widget (xml,"st2"))) > 0)
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
									  (glade_xml_get_widget (xml, "ct2")),
									  TRUE);
	else
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
									  (glade_xml_get_widget (xml, "ct2")),
									  FALSE);

	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
								  (glade_xml_get_widget (xml, "con2")),
								  !gtk_toggle_button_get_active
								  (GTK_TOGGLE_BUTTON
								   (glade_xml_get_widget (xml, "c2"))));
}


void
on_st3_value_changed (void)
{
	if (gtk_spin_button_get_value (GTK_SPIN_BUTTON
								   (glade_xml_get_widget (xml,"st3"))) > 0)
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
									  (glade_xml_get_widget (xml, "ct3")),
									  TRUE);
	else
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
									  (glade_xml_get_widget (xml, "ct3")),
									  FALSE);

	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
								  (glade_xml_get_widget (xml, "con3")),
								  !gtk_toggle_button_get_active
								  (GTK_TOGGLE_BUTTON
								   (glade_xml_get_widget (xml, "c3"))));
}


void
on_st4_value_changed (void)
{
	if (gtk_spin_button_get_value (GTK_SPIN_BUTTON
								   (glade_xml_get_widget (xml,"st4"))) > 0)
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
									  (glade_xml_get_widget (xml, "ct4")),
									  TRUE);
	else
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
									  (glade_xml_get_widget (xml, "ct4")),
									  FALSE);

	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
								  (glade_xml_get_widget (xml, "con4")),
								  !gtk_toggle_button_get_active
								  (GTK_TOGGLE_BUTTON
								   (glade_xml_get_widget (xml, "c4"))));
}


void
on_st5_value_changed (void)
{
	if (gtk_spin_button_get_value (GTK_SPIN_BUTTON
								   (glade_xml_get_widget (xml,"st5"))) > 0)
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
									  (glade_xml_get_widget (xml, "ct5")),
									  TRUE);
	else
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
									  (glade_xml_get_widget (xml, "ct5")),
									  FALSE);

	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
								  (glade_xml_get_widget (xml, "con5")),
								  !gtk_toggle_button_get_active
								  (GTK_TOGGLE_BUTTON
								   (glade_xml_get_widget (xml, "c5"))));
}


void
on_st6_value_changed (void)
{
	if (gtk_spin_button_get_value (GTK_SPIN_BUTTON
								   (glade_xml_get_widget (xml,"st6"))) > 0)
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
									  (glade_xml_get_widget (xml, "ct6")),
									  TRUE);
	else
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
									  (glade_xml_get_widget (xml, "ct6")),
									  FALSE);

	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
								  (glade_xml_get_widget (xml, "con6")),
								  !gtk_toggle_button_get_active
								  (GTK_TOGGLE_BUTTON
								   (glade_xml_get_widget (xml, "c6"))));
}


void
on_st7_value_changed (void)
{
	if (gtk_spin_button_get_value (GTK_SPIN_BUTTON
								   (glade_xml_get_widget (xml,"st7"))) > 0)
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
									  (glade_xml_get_widget (xml, "ct7")),
									  TRUE);
	else
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
									  (glade_xml_get_widget (xml, "ct7")),
									  FALSE);

	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
								  (glade_xml_get_widget (xml, "con7")),
								  !gtk_toggle_button_get_active
								  (GTK_TOGGLE_BUTTON
								   (glade_xml_get_widget (xml, "c7"))));
}


void
on_bt_clear_all_clicked (void)
{

	gtk_spin_button_set_value (GTK_SPIN_BUTTON
							   (glade_xml_get_widget (xml, "st0")), 0);
	gtk_spin_button_set_value (GTK_SPIN_BUTTON
							   (glade_xml_get_widget (xml, "st1")), 0);
	gtk_spin_button_set_value (GTK_SPIN_BUTTON
							   (glade_xml_get_widget (xml, "st2")), 0);
	gtk_spin_button_set_value (GTK_SPIN_BUTTON
							   (glade_xml_get_widget (xml, "st3")), 0);
	gtk_spin_button_set_value (GTK_SPIN_BUTTON
							   (glade_xml_get_widget (xml, "st4")), 0);
	gtk_spin_button_set_value (GTK_SPIN_BUTTON
							   (glade_xml_get_widget (xml, "st5")), 0);
	gtk_spin_button_set_value (GTK_SPIN_BUTTON
							   (glade_xml_get_widget (xml, "st6")), 0);
	gtk_spin_button_set_value (GTK_SPIN_BUTTON
							   (glade_xml_get_widget (xml, "st7")), 0);
}


void
on_b_about_clicked (void)
{
	GtkAboutDialog *about = GTK_ABOUT_DIALOG (gtk_about_dialog_new ());
	
	gtk_about_dialog_set_name (about, PACKAGE);
	gtk_about_dialog_set_version (about, VERSION);
	gtk_about_dialog_set_comments (about, COMMENTS);
	gtk_about_dialog_set_copyright (about, COPYING);
	
	//gtk_about_dialog_set_logo (about, 
	
		
	gtk_dialog_run (GTK_DIALOG (about));
	gtk_widget_destroy (GTK_WIDGET(about));
}


void connect_signals (void)
{
	glade_xml_signal_connect (xml, "on_c0_toggled",
							  G_CALLBACK(on_c0_toggled));
	glade_xml_signal_connect (xml, "on_c1_toggled",
							  G_CALLBACK(on_c1_toggled));
	glade_xml_signal_connect (xml, "on_c2_toggled",
							  G_CALLBACK(on_c2_toggled));
	glade_xml_signal_connect (xml, "on_c3_toggled",
							  G_CALLBACK(on_c3_toggled));
	glade_xml_signal_connect (xml, "on_c4_toggled",
							  G_CALLBACK(on_c4_toggled));
	glade_xml_signal_connect (xml, "on_c5_toggled",
							  G_CALLBACK(on_c5_toggled));
	glade_xml_signal_connect (xml, "on_c6_toggled",
							  G_CALLBACK(on_c6_toggled));
	glade_xml_signal_connect (xml, "on_c7_toggled",
							  G_CALLBACK(on_c7_toggled));
	
	glade_xml_signal_connect (xml, "on_closebutton_clicked",
							  G_CALLBACK (on_closebutton_clicked));
	glade_xml_signal_connect (xml, "on_all_on_clicked",
							  G_CALLBACK (on_all_on_clicked));
	glade_xml_signal_connect (xml, "on_all_off_clicked",
							  G_CALLBACK (on_all_off_clicked));
	glade_xml_signal_connect (xml, "on_bt_send_clicked",
							  G_CALLBACK (on_bt_send_clicked));

	glade_xml_signal_connect (xml, "on_st0_value_changed",
							  G_CALLBACK (on_st0_value_changed));
	glade_xml_signal_connect (xml, "on_st1_value_changed",
							  G_CALLBACK (on_st1_value_changed));
	glade_xml_signal_connect (xml, "on_st2_value_changed",
							  G_CALLBACK (on_st2_value_changed));
	glade_xml_signal_connect (xml, "on_st3_value_changed",
							  G_CALLBACK (on_st3_value_changed));
	glade_xml_signal_connect (xml, "on_st4_value_changed",
							  G_CALLBACK (on_st4_value_changed));
	glade_xml_signal_connect (xml, "on_st5_value_changed",
							  G_CALLBACK (on_st5_value_changed));
	glade_xml_signal_connect (xml, "on_st6_value_changed",
							  G_CALLBACK (on_st6_value_changed));
	glade_xml_signal_connect (xml, "on_st7_value_changed",
							  G_CALLBACK (on_st7_value_changed));
	
	glade_xml_signal_connect (xml, "on_bt_clear_all_clicked",
							  G_CALLBACK (on_bt_clear_all_clicked));
	glade_xml_signal_connect (xml, "on_b_about_clicked",
							  G_CALLBACK (on_b_about_clicked));
}

