import serial

# Open COM port for reading
ser_port = serial.Serial('COM13', 9600)

# Open Arduino serial port for writing
arduino_port = serial.Serial('COM5', 9600)

while True:
    # Read data from COM port 
    data = ser_port.readline().decode().strip()
    
    # Forward data to Arduino
    arduino_port.write(data.encode())
