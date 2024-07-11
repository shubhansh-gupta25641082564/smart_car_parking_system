# Smart Car Parking System

Welcome to the Smart Car Parking System project! This IoT-based solution aims to revolutionize the traditional parking system by integrating smart features such as a smart billing system, car slot counter, and autonomous barriers for entry and exit. This project is built using Arduino Uno R3, IR sensors, servo motors, an LCD, and other essential components.

## Features

### 1. Smart Billing System
The smart billing system calculates the parking fee for each vehicle based on the duration of the parking. Each slot is equipped with an individual IR sensor that tracks the time a vehicle occupies the slot. The system then computes the bill accurately and displays it on an LCD screen.

*How It Works:*

1. *Parking:*
   - Each parking slot has an individual IR sensor to detect vehicle presence.
   - The system records the time the vehicle occupies the slot.

2. *Billing:*
   - When the vehicle leaves the slot, the system calculates the parking fee based on the duration.
   - The bill amount is displayed on the LCD.

### 2. Smart Car Slot Counter

The Smart Car Slot Counter is an essential component of the Smart Car Parking System, providing real-time information on the availability of parking slots. This feature is achieved using IR sensors strategically placed at the entry and exit barriers.

*How It Works:*

1. *Vehicle Detection at Barriers:*
   - IR sensors are placed at both the entry and exit barriers of the parking area.
   - When a vehicle approaches the entry barrier, the IR sensor detects its presence and triggers the slot counter system.

2. *Slot Availability Update:*
   - Upon detection of a vehicle at the entry barrier, the system checks the current count of available parking slots.
   - If slots are available, the system updates the count, reducing the number of available slots by one as the vehicle enters.
   - Conversely, when a vehicle approaches the exit barrier, the IR sensor detects it and the system increases the count of available slots by one as the vehicle exits.

3. *Real-Time Display:*
   - The current status of available slots is displayed on an LCD screen, providing real-time information to drivers.

By constantly monitoring the entry and exit of vehicles, the Smart Car Slot Counter ensures accurate and up-to-date information on parking slot availability, making it easier for drivers to find parking.

### 3. Autonomous Barriers

The Autonomous Barriers in the Smart Car Parking System are designed to manage the entry and exit of vehicles based on two primary factors: detection of a car by an IR sensor and the availability of parking slots. These barriers are operated by servo motors, ensuring smooth and automated control.

*How It Works:*

1. *Detection of a Car by IR Sensor:*
   - At both the entry and exit points, IR sensors are installed to detect the presence of a vehicle.
   - When a vehicle approaches the entry barrier, the IR sensor identifies its presence and sends a signal to the barrier control system.
   - Similarly, when a vehicle approaches the exit barrier, the IR sensor detects it and triggers the barrier control system.

2. *Slot Availability Check:*
   - Upon detection of a vehicle at the entry barrier, the system checks the availability of parking slots.
   - If there are available slots, the system allows the barrier to open by activating the servo motor.
   - If no slots are available, the barrier remains closed, preventing entry.

3. *Barrier Operation:*
   - *Entry Barrier:*
     - When a vehicle is detected and slots are available, the servo motor operates to open the barrier.
     - After the vehicle passes through, the barrier closes automatically.
   - *Exit Barrier:*
     - When a vehicle approaches the exit barrier, the IR sensor detects it and the servo motor opens the barrier.
     - Once the vehicle exits, the barrier closes, and the slot counter updates to reflect the newly available slot.

By incorporating these two factors, the Autonomous Barriers ensure controlled and efficient management of vehicle entry and exit, preventing overcrowding and ensuring optimal use of available parking spaces.

## Components

- *Arduino Uno R3:* The brain of the project, responsible for controlling all the components and processing data.
- *IR Sensors:* Used for detecting the presence of vehicles at entry/exit points and in individual parking slots.
- *Servo Motors:* Used to operate the autonomous barriers.
- *LCD:* Displays information such as the bill amount and slot availability.
- *Jumper Wires & Breadboard:* For creating connections between components.
- *Arduino IDE:* The software used to write and upload code to the Arduino board.

## Installation

1. *Hardware Setup:*
   - Connect the Arduino Uno R3 to the breadboard.
   - Connect IR sensors to detect vehicle presence at entry/exit points and in parking slots.
   - Connect servo motors to operate the barriers.
   - Connect the LCD to display information.
   - Use jumper wires to connect all components appropriately.

2. *Software Setup:*
   - Install the Arduino IDE from the [official website](https://www.arduino.cc/en/Main/Software).
   - Download or clone this repository to your local machine.
   - Open the project file in the Arduino IDE.
   - Upload the code to the Arduino Uno R3.

## Conclusion

The Smart Car Parking System is a comprehensive solution designed to make parking management more efficient and user-friendly. With features like smart billing, real-time slot counting, and autonomous barriers, this system significantly enhances the parking experience. We hope this project inspires further innovation in IoT-based solutions for everyday problems.
