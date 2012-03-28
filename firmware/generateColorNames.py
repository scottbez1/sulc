csv = open("webcolors.csv").read()

#inject "off" as a color
csv = "off,#000000\n" + csv

color_list = csv.split("\n")

names = ""
colors = ""

def hex_to_rgb(value):
    value = value.lstrip('#')
    lv = len(value)
    return tuple(int(value[i:i+lv/3], 16) for i in range(0, lv, lv/3))

for y in color_list:
    if (not "," in y):
        continue
    (name,hex) = y.split(",")
    names = names + name.lower()
    (r,g,b) = hex_to_rgb(hex)
    colors = colors + "    {" + str(len(name)) + "," + str(r) + "," + str(g) + "," + str(b) + "},\n"


print "const Color colors[] PROGMEM = {"
print colors
print "};"
print
print
print "const char COLOR_NAMES[] PROGMEM = \"" + names + "\";" 
