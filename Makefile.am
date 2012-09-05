## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

pixmaps_DATA = avrusb.png
pixmapsdir = $(datadir)/@PACKAGE@/pixmaps

bin_PROGRAMS = gpowerswitch

gpowerswitch_SOURCES = \
	powerSwitch.c powerSwitch.h \
	psg-messages.c psg-messages.h \
	psg-callbacks.c psg-callbacks.h \
	main.c 

gpowerswitch_LDADD = @PACKAGE_LIBS@


EXTRA_DIST = \
	gPowerSwitch.glade gPowerSwitch.gladep \
	avrusb.png 
