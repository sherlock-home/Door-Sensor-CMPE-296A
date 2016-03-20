# Door Sensor - Lab Assignment

This Lab Assignment covers the understanding of the Arduino Uno, Raspberry Pi, GPIO pins,
sensors and application development for the devices.

- [Arduino] Build a door sensor that:
● Can broadcast signals over RF (Radio Frequency)
● Should have a Push Button Switch to turn the sensor on/off.
● Should have an LED to indicate if the sensor is ON or OFF
● Should use a second LED to indicate that the door is open by making the LED blink.


- [Raspberry Pi] Build a gateway that:
● Can receive signals over RF
● Should have a s ingle RGB LED to indicate if the door is open or closed (red = door
open, green = door closed)
● Should dump the output to the console/terminal stating whether the door is open or
closed.
● Should also dump the time in seconds for the time the door is open.


-- Instructions for Connections and Setup:

- Arduino:
1. Door LED to indicate door Open/Close – GPIO Pin 13
2. Switch to enable and disable door sensor – GPIO Pin 7
3. Status of Sensor On/Off – GPIO Pin 4
4. Connection to Door Sensor – GPIO Pin 2
5. Door Sensor Data Open/Close Codes Transmit– GPIO Pin 10
We are using GPIO pin# 10 as output pin which acts as input to Data In of Tx. The baud rate of transmission is 9600. The pictures show the circuit diagrams for Arduino.

- RaspberryPi:
1. Door Sensor Data Open/Close Codes Receive – GPIO Pin 2
2. Door Open Red LED for Single RGB LED – GPIO Pin 3
3. Door Closed Green LED for Single RGB LED – GPIO Pin 4
We are using Data out pin from the RF Receiver as input to GPIO pin# 2 of Raspberry PI. The pictures show the circuit diagrams for RaspberryPi.
Running the Codes:

- Arduino:
1. Connect the circuit as shown in the pictures for Arduino and RF-Tx module.
2. Import the “Arduino_Transmitter.imo” file.
3. Verify and Install it on Arduino.
4. Move around the Door sensor magnet to open and close the door.

- RaspberryPi:
1. Connect the circuit as shown in the pictures for RaspberryPi and RF-Rx module.
2. Connect to RaspberryPi via SSH.
3. Build the DoorSensor.cpp file using the Make –f MakeFile command.
4. Make sure make file contains all the dependencies of wiringPi and RFSwitch files.
5. On successful build an executable would be generated and run the file using command “./DoorSensor”

-- Operation:
1. Both the modules are active
2. Try opening and closing the door my moving the magnet of door sensor near and away the reed switch.
3. Notice the terminal, it will show the current status of the door if it is open/closed.
4. Also see the time for which it was open.
