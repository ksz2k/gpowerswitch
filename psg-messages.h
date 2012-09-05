

#ifndef _POWERSWITCH_MSGS
#define _POWERSWITCH_MSGS

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif


GtkWidget *psg_message_dialog ( /*GtkWidget *, */ GtkMessageType, gchar *,
							   ...);

/* shows message dialog with OK button
	GtkMessageTypes:
	GTK_MESSAGE_INFO,
	GTK_MESSAGE_WARNING,
	GTK_MESSAGE_QUESTION,
	GTK_MESSAGE_ERROR */





#endif
