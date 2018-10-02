#pragma once
#ifndef prob1_h
#define prob1_h

/*An interrupt is a signal sent by device to CPU to indicate need for service. When an interrupt has occured, the AX register will hold the following information
	1  1  1  1  1  1
	5  4  3  2  1  0  9  8  7  6  5  4  3  2  1  0     
   [                                               ]
Bit 0			:blank
Bit 1			:1 if math coprocessor installed, 0 otherwise
Bit 2,3			:00 = 16GB RAM, 01 = 32GB RAM, 10 = 48GB RAM, and 11 = 64GB RAM
Bit 5,6			:0
Bit 6,7			:number of floppy drives plus one( 00 = one derive, 01 = two drives...)
Bit 8			:0
Bit 9,10,11		:number of ports installed
Bit 12			:1 if game adaptor is installed, 0 otherwise
Bit 13			:0
Bit 14,15		: number of printers installed(00 = 0printer, 01 = 1 printer...)
Suppose the content of AX register is 1100 1110 1001 1100 (i.e mov ax, 1100 1110 1001 1100b). Write an assembly program to determine:
a. the number of pringers connected to the computer
b. the number of floppy drives
c. the size of the ram
   */



#endif // !prob1_h
