import bluetooth


#SENDS THINGS
def sendMessage(device,message):
    try:
        device.send(message.encode())
        print(message)
    except KeyboardInterrupt:
        device.close()

#CONNECTS TO DEVICE
def connect():
    address = "00:22:09:01:ca:87"
    port = 1
    device = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
    device.connect((address, port))

    return device

