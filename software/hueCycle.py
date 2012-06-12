#!/usr/bin/python
import colorsys
import serial
import time

port = serial.Serial('/dev/ttyACM0', 115200)

def send(val):
  port.write(chr(val))

SCALE = 100

hue = 0

try:
    while True:
      hue += 0.003
      if hue > 1:
        hue = 0

      (r,g,b) = colorsys.hsv_to_rgb(hue, 1, 1);

      send(255)
      send(0)
      send(int(r*SCALE))
      send(int(g*SCALE))
      send(int(b*SCALE))
      send(int(r*SCALE))
      send(int(g*SCALE))
      send(int(b*SCALE))
      time.sleep(0.01)
except KeyboardInterrupt:
    send(255)
    send(0)
    send(0)
    send(0)
    send(0)
    send(0)
    send(0)
    send(0)
    exit()
