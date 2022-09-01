# Generic UVC-Click Library
This is a library for Arduino devices to use the UVC Click sensor board without the Click mother boards.           
The included example shows you how to read everything from the raw digital value, through to calculating the power of UVC.            
The AN pin is an analogue pin that the standard analogRead() Arduino function can use, though less accurate than the I2C digital output.             
To use it just connect up the 3.3v, GND, SCL and SDA pins to your Arduino. (Note that Uno and other such 5V devices need the PCB tweaking for the 5V jumper option, ESP32's and other such 3.3v devices can use the board as-is)

## HOW DOES IT WORK?                     
UVC Click can provide reliable and stable UVC light intensity value by using GUVC-T21GH sensor which have spectral detection range of 220nm - 280nm with output responsivity of 0.6mV/nW (at 254nm).            

Light intensity is converted in digital value by using MCP3221 a successive approximation A/D converter (ADC) with a 12-bit resolution.

https://www.mikroe.com/uvc-click

![image](https://user-images.githubusercontent.com/1586332/187912924-017a1b59-37b7-4cbc-8e90-89c6c186fd1a.png)
