#!/usr/bin/python
"""
###########################################
#     Simple USB LED Controller - SULC    #
#        Copyright 5012 Scott Bezek       #
###########################################

    This file is part of SULC.

    SULC is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    SULC is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with SULC.  If not, see <http://www.gnu.org/licenses/>

"""


"""
This program reads webcolors.csv to get rgb and color name info
and writes it out to colorNames.h as PROGMEM arrays for the avr
to read
"""


# http://stackoverflow.com/a/214657
def hex_to_rgb(value):
    value = value.lstrip('#')
    lv = len(value)
    return tuple(int(value[i:i+lv/3], 16) for i in range(0, lv, lv/3))


def getColorTable():
    ct = ""

    csv = open("webcolors.csv").read()

    #inject "off" as a color
    csv = "off,#000000\n" + csv

    color_list = csv.split("\n")

    divisor = 2

    names = ""
    colors = ""
    for y in color_list:
        if (not "," in y):
            continue
        (name,hex) = y.split(",")
        names = names + name.lower()
        (r,g,b) = hex_to_rgb(hex)
        colors = colors + "    {" + str(len(name)) + "," + str(r/divisor) + "," + str(g/divisor) + "," + str(b/divisor) + "},\n"


    ct += "const Color colors[] PROGMEM = {\n"
    ct += colors
    ct += "\n"
    ct += "};\n"
    ct += "\n\n"
    ct += "const char COLOR_NAMES[] PROGMEM = \"" + names + "\";\n" 
    return ct


template = open("colorNames.tpl.h")
output = open("colorNames.h", "w")

output.write("/*\n\nNOTE:\nTHIS FILE IS AUTOMATICALLY GENERATED\n\nTO MODIFY:\nEdit webcolors.csv and run generateColorNames.py to regenerate this file.\n\n*/\n\n\n\n\n")

for line in template:
    if line.startswith("###COLOR_TABLE###"):
        output.write(getColorTable())
    else:
        output.write(line)

template.close()
output.close()
