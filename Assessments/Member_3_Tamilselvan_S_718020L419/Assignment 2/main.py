import random
while(True):
    o=random.randint(10,99)
    p=random.randint(10,99)
    if(o > 30 and p > 75):
     print("High Temprature and Humidity of:",o,p,"%","alarm is on")
    elif(o < 35 and p < 65):
         print("Normal Temprature and Humidity of:",o,p,"%","alarm is off")
         break