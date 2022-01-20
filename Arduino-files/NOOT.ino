/* File Name: NOOT.ino
 * Developer: kumoishibo
 * Date:      4 April 2021
 * Version:   0.1.0
 * Described: Arduino rangefinder for photogrammetry using the Benewake
 *            TF-Luna Lidar sensor and a TM1637 Display using a Pro-Micro (Leonardo)
 */
 
#include <Arduino.h>     // Every sketch needs this
#include <Wire.h>        // Instantiate the Wire library
#include <TFLI2C.h>      // TFLuna-I2C Library v.0.2.0 - from Bud Ryerson: https://github.com/budryerson/TFLuna-I2C
#include <TM1637Display.h>   //TM1637 Library v.1.2.0 - from Avishay Orpaz: https://github.com/avishorp/TM1637

#define CLK SCL
#define DIO SDA

TFLI2C tflI2C;

int16_t  tfDist;    // distance in centimeters
int16_t  tfAddr = TFL_DEF_ADR;  // Default I2C address

TM1637Display display(14,15); //(CLK, DIO)

void setup()
{
    Serial.begin( 115200);  // Initalize serial port
    Wire.begin();           // Initalize Wire library
}

void loop()
{
    display.setBrightness(0x0f);
    if( tflI2C.getData( tfDist, tfAddr)) // If read okay...
    {
        Serial.println(tfDist);         // print the data...
        display.showNumberDec(tfDist, false);
    }
    //else tflI2C.printStatus();          // else, print error.

    delay(120);   //Set range polling rate, default 120ms delay =~ 8hz
}
