"""Send the "magic" unlock command to the arduino that controls the door."""
import serial


def send(command):
    ard = serial.Serial('/dev/ttyUSB0', 9600)
    # print ard
    ard.write(command)

def unlock():
    # print "sending unlock..."
    send('u')
    # print "Done."
    

if __name__=="__main__":
    unlock()

