#!/usr/bin/python
import colorsys
import serial
import time
import random

port = serial.Serial('/dev/ttyACM0', 115200)

def send(val):
  port.write(chr(val))

SCALE = 60


try:
    while True:

      hue1 = random.random()
      sat1 = random.uniform(0.5, 1)
      (r1,g1,b1) = colorsys.hsv_to_rgb(hue1, sat1, 1);

      hue2 = random.random()
      sat2 = random.uniform(0.5, 1)
      (r2,g2,b2) = colorsys.hsv_to_rgb(hue2, sat2, 1);

      send(255)
      send(255)
      send(0)
      send(int(r1*SCALE))
      send(int(g1*SCALE))
      send(int(b1*SCALE))
      send(int(r1*SCALE))
      send(int(g1*SCALE))
      send(int(b1*SCALE))
      time.sleep(1)
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
