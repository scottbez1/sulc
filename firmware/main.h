/*
###########################################
#     Simple USB LED Controller - SULC    #
#        Copyright 2012 Scott Bezek       #
###########################################
*/

/*
    This file is part of SULC.

    SULC is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Foobar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with SULC.  If not, see <http://www.gnu.org/licenses/>
*/


#ifndef _MAIN_H_
#define _MAIN_H_

    #include <avr/io.h>
    #include <avr/wdt.h>
    #include <avr/power.h>
    #include <avr/interrupt.h>
    #include <string.h>
    #include <stdio.h>
    #include "Descriptors.h"
    #include <LUFA/Version.h>
    #include <LUFA/Drivers/USB/USB.h>

    void SetupHardware(void);

    void EVENT_USB_Device_Connect(void);
    void EVENT_USB_Device_Disconnect(void);
    void EVENT_USB_Device_ConfigurationChanged(void);
    void EVENT_USB_Device_ControlRequest(void);
#endif

