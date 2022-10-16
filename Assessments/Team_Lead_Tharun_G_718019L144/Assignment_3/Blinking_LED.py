# Code for Blinking LED in Raspberry Pi
# Written by : Tharun G - 718019L144

# importing necessary modules/libraries
import RPi.GPIO as GPIO
from gpiozero import LED 
import time 

# Configuring LED Pin
ledPin = LED(17)

while True:
    ledPin.on()
    print("LED - Turned ON")
    time.sleep(1)
    ledPin.off()
    print("LED - Turned OFF")
    time.sleep(1)

