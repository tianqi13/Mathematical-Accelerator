# give me code to connect to a wii controller

import cwiid
import time

def connect():
    print('Press 1+2 on your Wii Remote now ...')
    time.sleep(1)
    wii = cwiid.Wiimote()
    print('Connected to Wii Remote')
    return wii

def disconnect(wii):
    wii.close()
    print('Disconnected from Wii Remote')
    return

def getButtons(wii):
    return wii.state['buttons']

def getAccel(wii):
    return wii.state['acc']

def getIR(wii):
    return wii.state['ir_src']

def getNunchuckButtons(wii):
    return wii.state['nunchuk']['buttons']

def getNunchuckAccel(wii):
    return wii.state['nunchuk']['acc']


if __name__ == '__main__':
    wii = connect()
    try:
        while True:
            print(getButtons(wii))
            print(getAccel(wii))
            print(getIR(wii))
            print(getNunchuckButtons(wii))
            print(getNunchuckAccel(wii))
            time.sleep(1)
    except KeyboardInterrupt:
        disconnect(wii)
        print('Exiting...')
        exit()

