# CPLD_SPI_RPI

CPLD with Raspberry Pi

Somewhere around 2013 or 2014, I purchased a hardware for Raspberry Pi named Guzunty Pi from UK. The Guzunty Pi is a Xilinx XC9500XL Complex Programmable Logic Device, or CPLD.

As per Guzunty Pi wiki..

The goal of the Guzunty Pi to work as input/output expander in order to:

(1) Protect the delicate GPIO pins of the Raspberry Pi computer and

(2) Provide up to a net 25 additional input/output expansion lines.

A powerful feature of the Raspberry Pi is the row of GPIO (general-purpose input/output) pins along the top edge of the board. A 40-pin GPIO header is found on all current Raspberry Pi boards. Prior to the Pi 1 Model B+ (2014), boards comprised a shorter 26-pin header.

Hence, after removing I2C, SPI and PWM...not much GPIO pins are available for digital input or outputs. Thats where Guzunty Pi becomes useful.

Programmable logic devices, what are they?

They are an integrated circuit that you program using a hardware description language such as VHDL or Verilog.

There are several types of programmable logic available. Older versions like the programmable array logic (PAL), the generic array logic (GAL), the programmable logic device (PLD), the simple programmable logic device (SPLD).

The complex programmable logic device (CPLD) such as the XC9500XL from Xilinx, and the field programmable gate array (FPGA) such as the Spartan6 from Xilinx are some of the newer versions of programmable logic that are a result of improvements to the original types of devices.

A CPLD program is often referred to as a ‘core’ to distinguish it from a regular computer program. Cores can do things thousands of times faster than an equivalent computer program.

How does it work?

The XC9500XL CPLD is programmed using a file in Xilinx Serial Vector Format. Cores you can download and cores that you make yourself are stored in this format. To program the CPLD with a particular core you use a utility that decodes the XSVF file and sets up the device using four special programming and test pins called collectively the JTAG interface. The CPLD retains its program during power down, so you only need to program it once (or until you move on to another project). The programming process takes less than a minute and once programming is complete, the programming pins used on the Raspberry Pi GPIO can be repurposed if needed by your project.

The Raspberry Pi is equipped with one SPI bus that has 2 chip selects. The SPI master driver is disabled by default on Raspbian. To enable it, use raspi-config, or ensure the line dtparam=spi=on isn't commented out in /boot/config.txt, and reboot. If the SPI driver was loaded, you should see the device /dev/spidev0.0.

The SPI bus is available on the P1 Header:

MOSI    P1-19

MISO    P1-21

SCLK    P1-23   P1-24    CE0

GND     P1-25   P1-26    CE1

Signal name abbreviations:

SCLK - Serial CLocK

CE   - Chip Enable (often called Chip Select)

MOSI - Master Out Slave In

MISO - Master In Slave Out

MOMI - Master Out Master In

It's founder Derek Campbell used BCM2835 GPIO library and created API for programming Guzunty Pi. BCM2835 C library is good one. I prefer wiringPi C library written by Gordon Henderson as its very easy to use.

I have rewritten this program in C++ using Gordon Henderson's wiringPi SPI library.
To run this program...type following line in terminal

g++ cpld.cpp -lwiringPi -o cpld
