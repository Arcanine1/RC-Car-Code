import tkinter as tk
from tkinter import font
from BluetoothFunctions import *


def updateLeftSpeed(speed):
    
    if(int(speed)>0):
        direction ="F"
    else:
        direction ="R"

    absSpeed = str(abs(int(speed)))

    if(len(absSpeed) == 1):
        absSpeed = "0" + absSpeed

    sendMessage(device, "L" + absSpeed + direction)

def updateRightSpeed(speed):
    if(int(speed)>0):
        direction ="F"
    else:
        direction ="R"

    absSpeed = str(abs(int(speed)))

    if(len(absSpeed) == 1):
        absSpeed = "0" + absSpeed

    sendMessage(device, "R" + absSpeed + direction)

def stopCar():
    sendMessage(device, "stop")
    leftSpeed.set(0)
    rightSpeed.set(0)

#intialize methods
device =connect()
root = tk.Tk()
leftSpeed = tk.IntVar()
rightSpeed = tk.IntVar()
stopCar()


#creates radio buttons and speed
root.title("Bluetooth Terminal")
custom_font = font.Font(size=100)
left = tk.Scale(root, orient='vertical', length=200, variable= leftSpeed, from_=99, to=-99, font=custom_font, command= updateLeftSpeed)
right = tk.Scale(root, orient='vertical', length=200,variable= rightSpeed, from_=99, to=-99, font=custom_font, command= updateRightSpeed)
stop = tk.Button(root, text = "STOP", font= custom_font, command=stopCar, bg= "red")


# Set the grid positions to create a diamond layout

left.grid(row=1, column=0)
right.grid(row=1, column=2)
stop.grid(row=1,column=1)


root.mainloop()
