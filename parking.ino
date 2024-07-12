#include <Wire.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

// Constants
const int entryIRPin = 2;   // IR sensor pin for entry barrier
const int exitIRPin = 3;    // IR sensor pin for exit barrier
const int entryServoPin = 9; // Servo motor pin for entry barrier
const int exitServoPin = 10; // Servo motor pin for exit barrier
const int slotIRPins[] = {4, 5, 6, 7}; // IR sensor pins for individual slots
const int numSlots = sizeof(slotIRPins) / sizeof(slotIRPins[0]); // Number of parking slots

Servo entryServo;
Servo exitServo;
LiquidCrystal_I2C lcd(0x27, 16, 2); // Initialize the LCD (change this HEX address according to your LCD's HEX address)

// Variables
int availableSlots = numSlots; // Initially all slots are available
unsigned long slotStartTime[numSlots]; // Start time for each slot

void setup()
{
    Serial.begin(9600);
    entryServo.attach(entryServoPin);
    exitServo.attach(exitServoPin);
    pinMode(entryIRPin, INPUT);
    pinMode(exitIRPin, INPUT);
    for (int i = 0; i < numSlots; i++)
    {
        pinMode(slotIRPins[i], INPUT);
        slotStartTime[i] = 0;
    }
    lcd.init();
    lcd.backlight();
    updateLCD();
}
void loop()
{
    // Check for vehicle at entry barrier
    if (digitalRead(entryIRPin) == HIGH)
    {
        if (availableSlots > 0)
        {
            openEntryBarrier();
            delay(5000); // Delay for vehicle passage
            closeEntryBarrier();
            availableSlots--;
            Serial.println("Vehicle entered. Available slots: " + String(availableSlots));
            updateLCD();
        }
        else
        {
            Serial.println("No available slots. Entry denied.");
            // Display message on LCD
            lcd.setCursor(0, 1);
            lcd.print("No slots avail.");
        }
        // Delay to avoid rapid detection
        delay(1000);
    }
    // Check for vehicle at exit barrier
    if (digitalRead(exitIRPin) == HIGH)
    {
        openExitBarrier();
        delay(5000); // Delay for vehicle passage
        closeExitBarrier();
        availableSlots++;
        Serial.println("Vehicle exited. Available slots: " + String(availableSlots));
        updateLCD();
        // Delay to avoid rapid detection
        delay(1000);
    }
    // Check each slot for vehicle presence
    for (int i = 0; i < numSlots; i++)
    {
        if (digitalRead(slotIRPins[i]) == HIGH)
        {
            if (slotStartTime[i] == 0)
            {
                slotStartTime[i] = millis(); // Record the start time when a vehicle is detected
            }
        }
        else
        {
            if (slotStartTime[i] != 0)
            {
                unsigned long parkedTime = millis() - slotStartTime[i];
                slotStartTime[i] = 0; // Reset start time
                float billAmount = calculateBill(parkedTime);
                Serial.print("Vehicle left slot ");
                Serial.print(i);
                Serial.print(". Parking time: ");
                Serial.print(parkedTime / 1000);
                Serial.print(" seconds. Bill: $");
                Serial.println(billAmount);
                // Display bill amount on LCD
                lcd.setCursor(0, 1);
                lcd.print("Slot ");
                lcd.print(i);
                lcd.print(" Bill: $");
                lcd.print(billAmount);
            }
        }
    }
}
void openEntryBarrier()
{
    entryServo.write(0); // Open position
}
void closeEntryBarrier()
{
    entryServo.write(90); // Closed position
}
void openExitBarrier()
{
    exitServo.write(0); // Open position
}
void closeExitBarrier()
{
    exitServo.write(90); // Closed position
}
float calculateBill(unsigned long parkedTime)
{
    float ratePerSecond = 0.01; // Define your rate per second
    return parkedTime / 1000.0 * ratePerSecond;
}
void updateLCD()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Slots avail: ");
    lcd.print(availableSlots);
}