# DMX512 Demo for Arduino RS485 Shield
How use the RS485 Shield for DMX512 lighting control


![DMX512 Demo]](https://github.com/HWHardsoft/Arduino-DMX512-Demo/blob/main/assets/DMX_Arduino.jpg)

## Wiring
In this tutorial, we want to implement a Modbus RTU master and a slave that can communicate with each other. Therefore, we need two Arduino Uno R4s (the good old Rev3 will also work), two RS485 shields, and a few LEDs and buttons connected to the master and slave so that something ‘happens’. 
The RS485 uses two lines for signal transmission. These two signals are often labeled A and B on RS485 devices. Unfortunately, the use of the letters A and B is not uniformly regulated. In the RS485 Shield, "A" means R+/T+ (also known as D+) and "B" means R-/T- (also known as D-). This may also differ for other devices. For our test setup, we need to connect the two A terminals and the two B terminals of the shields via cables. 
Furthermore, an LED and push button are connected to both the master and slave via a small breadboard, for example, in accordance with the circuit diagram below. 

![Button and LED](https://github.com/HWHardsoft/MODBUS-RTU-with-Arduino-RS485-shield/blob/main/assets/Scheme_of_setup.png)


## Jumper setting 
JP1: 5V

Jumper setting for UNO R4:

![Jumper UNO R4](https://github.com/HWHardsoft/MODBUS-RTU-with-Arduino-RS485-shield/blob/main/assets/Jumper_setting_UNO_R4.png)
 
 
Jumper setting for UNO R3:

![Jumper UNO R3](https://github.com/HWHardsoft/MODBUS-RTU-with-Arduino-RS485-shield/blob/main/assets/Jumper_setting_UNO_R3.png)

## DIP Switch setting
S1: OFF-ON-ON-OFF

S2: OFF-OFF-ON-ON

S3: ON-OFF-ON-ON



## Hardware
- Arduino UNO Rev3 or R4
- [Zihatec RS485 Shield for Arduino](https://www.hwhardsoft.de/english/projects/rs485-arduino/)
- DMX LED Mini Spot


## Essential Libraries
Arduino's own RS485 and DMX libraries needed: 

![Library installation](https://github.com/HWHardsoft/MODBUS-RTU-with-Arduino-RS485-shield/blob/main/assets/install_cbs_modbus_libs.png)

## How it works
[![in Action](https://img.youtube.com/vi/MqWqR2RyUSY/0.jpg)](https://www.youtube.com/watch?v=MqWqR2RyUSY)



## License

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 2.1 of the License, or (at your option) any later version.
This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
