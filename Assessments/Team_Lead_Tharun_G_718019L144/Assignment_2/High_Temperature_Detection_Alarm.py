# High Temperature and Humidity detection using Alarm
import random as src
while True:
    temperature = src.randint(10,100)
    humidity = src.randint(10,100)
    if humidity>35 and temperature>60:
        print("Temperature:",temperature,"degree celsius")
        print("Humidity:",humidity,"grams/(meter^3)")
        print("ALARM ON")
    else:
        print("Temperature:",temperature,"degree celsius")
        print("Humidity:",humidity,"grams/(meter^3)")
        print("ALARM OFF")
    print("\n","*"*30,"\n",sep="")
    
