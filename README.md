gPowerSwitch
============

gPowerSwitch is a GTK+ based GUI (graphical user interface) for [Objective Development's](http://obdev.at) [PowerSwitch](http://www.obdev.at/products/vusb/powerswitch.html) - USB driven control switch. Program can be helpful when you don't like command line tools or when you just need a simple GUI for PowerSwitch. But remember, gPowerSwitch is only a PC application, for hardware project please go to OBDev's page.

Required libraries:
* GTK+ >= 2.6
* LibGLADE >= 2.0
* LibUSB


## Configuration and compilation ###

The configuration of Vendor and Device names can be done in `configure.in`
After change it you have to `./autogen.sh` the project
WARNING: It's must be the same as in the firmware!

In powerSwitch.h you can change the `PSG_ACTIVE` macro, I've defined it for easier
change of active state, because on my EvBoard it's zero..
