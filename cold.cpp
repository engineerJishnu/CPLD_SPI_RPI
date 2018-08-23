//g++ cpld.cpp -lwiringPi -o cpld

//-------Headers----------------------
#include <iostream>
#include <wiringPiSPI.h>
#include <unistd.h>

//--------Global variables---------------
// The Serial Peripheral Interface (SPI) is a communication protocol used to 
// transfer data between micro-computers like the Raspberry Pi and peripheral devices.
// These peripheral devices may be either sensors or actuators.
// SPI uses 4 separate connections to communicate with the peripheral device. 
// These connections are (a) serial clock (CLK), (b) Master Input Slave Output (MISO), 
// (c) Master Output Slave Input (MOSI) and Chip Select (CS).
// The clock pin sense pulses at a regular frequency, the speed at which the 
// Raspberry Pi and SPI device agree to transfer data to each other.
// The MISO pin is a data pin used for the master (in this case the Raspberry Pi) 
// to receive data from the peripheral data. Data is read from the bus after every clock pulse.
// The MOSI pin sends data from the Raspberry Pi to the peripheral device. 
// The device will take the value of the bus on the rising / falling  edge of the clock. 
// This means the value must be set before the clock is pulsed.
// the Chip Select line chooses which particular SPI device is in use. 
// If there are multiple SPI devices, they can all share the same CLK, MOSI, and MISO. 
// Only the selected device has the Chip Select line set low, 
// while all other devices have their CS lines set high. 
// A high Chip Select line tells the SPI device to ignore all of the commands and traffic on the rest of the bus.
// Here the CHANNEL is CE / CS in Raspberry Pi SPI. it can be 0 or 1, depending upon which
// pin its connected. CPLD is connected to CE0.
// The SPI bus is available on the P1 Header:

// MOSI    P1-19
// MISO    P1-21
// SCLK    P1-23   P1-24    CE0
// GND     P1-25   P1-26    CE1

const int CHANNEL = 0;
unsigned char buffer[2];
int result;

//--------Functions---------------------
template <class T>
void printVal(T value) { 
	std::cout << value << std::endl;
}

void exercise_outputs(uint16_t a, uint16_t b) {
    buffer[0] = a & 0xff;
    result = wiringPiSPIDataRW(CHANNEL, buffer, 2);
    usleep(50000);

    buffer[0] = b & 0xff;
    result = wiringPiSPIDataRW(CHANNEL, buffer, 2);
    usleep(100000);
}


//----------main function------------------
int main()
{
   	int fd;
	printVal("initializing");
	// Configure the interface.
   	// CHANNEL insicates chip select,
   	// 500000 indicates bus speed.
   	fd = wiringPiSPISetup(CHANNEL, 500000);

	printVal("Init Result");
	printVal("FLASHING ALL LED");
	while(1){
    		exercise_outputs(0xff, 0x00);
        	}
	return 0;
}
