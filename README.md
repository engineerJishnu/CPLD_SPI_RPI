# CPLD_SPI_RPI
CPLD with Raspberry Pi

I have Guzunty Pi CPLD purchased from UK somewhere around 2014. As per Guzunty Pi wiki

The purpose of the Guzunty Pi input/output expander is to (1) Protect the delicate GPIO pins of the Raspberry Pi computer and
(2) Provide up to a net 25 additional input/output expansion lines.

the Guzunty is a Xilinx XC9500XL Complex Programmable Logic Device, or CPLD.

A CPLD is like several large breadboards laid out on your desk, full of every combination of logic devices you are ever going to need. It is waiting to be told what to do. It doesn't need a host of jumper wires like a breadboard would. It can be reprogrammed again and again (even at runtime), and it is small enough to fit on top of your Pi.

A CPLD program is often referred to as a ‘core’ to distinguish it from a regular computer program. Cores can do things thousands of times faster than an equivalent computer program.

How does it work?

The XC9500XL CPLD is programmed using a file in Xilinx Serial Vector Format. Cores you can download and cores that you make yourself are stored in this format. To program the CPLD with a particular core you use a utility that decodes the XSVF file and sets up the device using four special programming and test pins called collectively the JTAG interface. The CPLD retains its program during power down, so you only need to program it once (or until you move on to another project). The programming process takes less than a minute and once programming is complete, the programming pins used on the Raspberry Pi GPIO can be repurposed if needed by your project.
