# ESP32 & Arduino Nano Inter-Port Serial Communication

A method for making two microcontrollers talk to each other through the
same computer over USB serial, without any extra wired or wireless link
between them. An ESP32 reads a DS18B20 temperature sensor, and an
Arduino Nano reacts to the data by blinking its built-in LED when the
temperature exceeds 40 °C.

## Background
Microcontrollers often need to exchange data. Wired protocols (I2C, SPI,
UART) and wireless links are common, but sometimes a device has no free
UART pins, or a clock speed difference makes direct communication lossy.
Another option is inter-port communication between devices connected to
the same computer. This is not possible directly, because only one
program can use a serial port at a time, so an application on the PC is
needed to pass the data between the ports.

## How It Works
1. The ESP32 reads the DS18B20 and continuously sends the temperature to
   its own USB serial (COM) port.
2. The Arduino Nano is connected to a separate COM port on the same PC.
3. A bridge on the PC reads the data from the ESP32's port and forwards
   it to the Nano's port.
4. The Nano reads the incoming temperature and blinks its built-in LED
   when it exceeds 40 °C.

## Methods Used

**Method 1: RealTerm (Serial Capture Program v2.0.0.70)**
1. Open RealTerm and go to the **Port** tab. Set the baud rate and the
   ESP32's port (COM13 on our PC), then click **Open**. RealTerm now
   reads the data stream from the ESP32.
2. Go to the **Echo** tab, set the baud rate, select the Arduino's port
   (COM5 on our PC), and tick the **Echo** box. RealTerm now forwards
   the same data to the Arduino Nano.

**Method 2: Python script**
A short script using the `pyserial` library reads each line from the
ESP32's port and writes it to the Arduino's port (see
`python/serial_bridge.py`).

## Hardware
- ESP32 [board name]
- Arduino Nano
- DS18B20 temperature sensor
- 2 USB cables (one per board)
- PC (Windows) with two available USB ports

## Software
- Arduino IDE
- RealTerm Serial Capture Program v2.0.0.70
- Python 3 with the `pyserial` library (`pip install pyserial`)

## Setup
1. Connect the ESP32 and the Arduino Nano to the PC with USB cables.
2. Find each board's COM port in Windows Device Manager. On our PC the
   ESP32 was on COM13 and the Arduino Nano on COM5. Yours will likely
   differ, so change the port numbers in RealTerm or in the script.
3. Upload the ESP32 sketch (DS18B20 reading) and the Nano sketch (LED
   logic).
4. Use the same baud rate (9600) in the sketches, RealTerm, and the
   Python script.
5. Run either the RealTerm setup or the Python script. The Nano's LED
   blinks when the temperature exceeds 40 °C.

## Screenshots & Images
<img width="491" height="313" alt="Reading Serial Data" src="https://github.com/user-attachments/assets/bf18afc1-4a24-4c53-a7fa-9c4271111916" />
<img width="503" height="321" alt="Data Echo on desired Port" src="https://github.com/user-attachments/assets/5f013d07-db0a-42f5-aa26-12f012e5fd88" />
<img width="1242" height="695" alt="Using Python App" src="https://github.com/user-attachments/assets/05424c26-a454-4994-a39d-498033d97a0b" />



## Repository Contents
- `esp32/` - ESP32 sketch (DS18B20 reading)
- `nano/` - Arduino Nano sketch (LED logic)
- `python/` - Python bridge script (`serial_bridge.py`)
- `images/` - screenshots and photos

## Author
Zain Rizwan - Electrical Engineer<br>
Embedded Systems Lab project, University (2024)
