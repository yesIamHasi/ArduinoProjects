import serial, subprocess

def notify(message, title):
    subprocess.Popen(['notify-send',title, message])
    return

def readSerial(port, baudrate):
    UNO = serial.Serial(port, baudrate)

    while True:
        while (UNO.inWaiting() == 0):
            pass
        reading = UNO.readline()
        try:
            reading = int(reading)
            if reading < 1020:
                print ("Someone is at the door")
                notify('Someone is at the door', 'Smart Door')
        except ValueError:
            print ('[!] Non readible')


if __name__ == '__main__':
    readSerial('/dev/tty/ACM0', 1000000)
