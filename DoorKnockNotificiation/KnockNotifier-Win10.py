import serial
from win10toast import ToastNotifier
toast = ToastNotifier()


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
                toast.show_toast('Smart Door', 'Someone is at the door')
        except ValueError:
            print ('[!] Non readible')


if __name__ == '__main__':
readSerial('/dev/tty/COM1', 1000000)
