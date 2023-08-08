import bluetooth
import tkinter as tk

#CONNECTS TO DEVICE
address = "00:22:09:01:ca:87"
port = 1
device = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
device.connect((address, port))

#SENDS THINGS
try:
    while True:
        message = input("Enter a message to send: ")
        if message.lower() == "exit":
            break

        device.send(message.encode())
except KeyboardInterrupt:
    pass

# Close the Bluetooth connection
device.close()
