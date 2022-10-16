# Traffic Lights using Raspberry Pi
# Written by : Tharun G - 718019L144

# importing necessary modules
import time 
import RPi.GPIO as GPIO

# Configuring the pins as output
GPIO.setmode(GPIO.BOARD)
GPIO.setup(11, GPIO.OUT)
GPIO.setup(12, GPIO.OUT)
GPIO.setup(13, GPIO.OUT)

# Representing each led in traffic light with a variable
red = 11
amber = 12
green = 13

while True:
    GPIO.output(11,True)
    print("RED LIGHT - ON")
    print("Time Left: ")
    for i in range(45):
        print(45-i,end="\r")
        time.sleep(1)
    print(0)
    GPIO.output(11,False)

    # GPIO.output(12,True)
    print("YELLOW LIGHT - ON")
    print("Time Left: ")
    for i in range(10):
        print(10-i,end="\r")
        time.sleep(1)
    print(0)
    GPIO.output(12,False)

    GPIO.output(13,True)
    print("GREEN LIGHT - ON")
    print("Time Left: ")
    for i in range(60):
        print(60-i,end="\r")
        time.sleep(1)
    print(0)
    GPIO.output(13,False)
    
# Note: In this code, instead of continuously printing the time left 
# in new lines, '/r' (Carriage return) is used to update the time 
# in the same line each second.