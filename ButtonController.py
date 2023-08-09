import tkinter as tk
from tkinter import font
from BluetoothFunctions import *

def update():
    speed = str(speedValue.get())

    if(len(speed) == 1):
        speed = "0" + speed

    sendMessage(device, direction.get() + speed)

def updateSpeed(speed):
    speed = str(speed)

    if(len(speed) == 1):
        speed = "0" + speed
    sendMessage(device, direction.get() + speed)

def stopCar():
    sendMessage(device, "stop")
    speedValue.set(0)


device =connect()
stopCar()

#creates base
root = tk.Tk()
root.title("Bluetooth Terminal")


#creates radio buttons and speed
custom_font = font.Font(size=100)
direction = tk.StringVar()
speedValue = tk.IntVar()
speedValue.set(0)
forward = tk.Radiobutton(root, text='Forward', variable=direction, value='F', font= custom_font, command= update)
backward = tk.Radiobutton(root, text='Backward', variable=direction, value='B', font= custom_font, command= update)
left = tk.Radiobutton(root, text='Left', variable=direction, value='A', font= custom_font,command= update)
right = tk.Radiobutton(root, text='Right', variable=direction, value='D', font= custom_font, command= update)
speed = tk.Scale(root, orient='horizontal',variable= speedValue, length=200, from_=0, to=99, font=custom_font, command= updateSpeed)
stop = tk.Button(root, text = "STOP", font= custom_font, command=stopCar, bg= "red")


# Set the grid positions to create a diamond layout
forward.grid(row=0, column=1)
backward.grid(row=2, column=1)
left.grid(row=1, column=0)
right.grid(row=1, column=2)
speed.grid(row=1, column=1)
stop.grid(row=2,column=2)


root.mainloop()
