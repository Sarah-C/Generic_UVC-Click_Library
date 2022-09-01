# Generic UVC-Click Library
This is a library for Arduino devices to use the UVC Click sensor board without needing the expensive Click development "mother-boards".           

The included example shows you how to read everything from the raw digital value, through to calculating the power of UVC in mW/cm2.            

The AN pin is an analogue pin that the standard analogRead() Arduino function can use, though less accurate than the I2C digital output.             

To use it just connect up the 3.3v, GND, SCL and SDA pins to your Arduino. (Note that Uno and other such 5V devices need the PCB tweaking for the 5V jumper option, ESP32's and other such 3.3v devices can use the board as-is)


## How does it work?        
The Mikroe "Click-Boards" use a mikroBUS™ socket comprising a pair of 1×8 female headers with a proprietary pin configuration and silkscreen markings. The pinout (always laid out in the same order) consists of three groups of communications pins (SPI, UART and I2C), six additional pins (PWM, Interrupt, Analog input, Reset and Chip select), and two power groups (+3.3V and 5V).      

These can be plugged directly into Mikroe's large development boards without needing to organise the wiring, and come with libraries that use Mikroe's own environment using logging features, and exhaustive Click-board control code.        

If you want to just use a board with Arduino the Click-board libraries won't work becauses they expect all the other hardware to be there too.           

This library was created from the original UVC Click board's library, in order to access the board via the I2C pins on the board, and uses the same calculations to produce the same values as the Click board library for milli-volt output, and power in mW/cm2.
![image](https://user-images.githubusercontent.com/1586332/187917020-4744a991-0fd4-47d9-97fa-1cf0f09709dc.png)

## What is the UVC Click board         
UVC Click can provide reliable and stable UVC light intensity value by using GUVC-T21GH sensor which have spectral detection range of 220nm - 280nm with output responsivity of 0.6mV/nW (at 254nm).            

Light intensity is converted in digital value by using MCP3221 a successive approximation A/D converter (ADC) with a 12-bit resolution.

https://www.mikroe.com/uvc-click

![image](https://user-images.githubusercontent.com/1586332/187912924-017a1b59-37b7-4cbc-8e90-89c6c186fd1a.png)
