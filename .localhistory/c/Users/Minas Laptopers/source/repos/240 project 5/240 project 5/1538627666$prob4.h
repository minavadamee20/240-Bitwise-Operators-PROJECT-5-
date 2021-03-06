#pragma once
#ifndef prob4_h
#define prob4_h
#include <iostream>
/*The sSheaton Hotel is a 16th floor building. Suppose each bits of AX register represent one floor (the right most bit is representing the first floor). Ten people got into the elevator on the first floor 
and each pressed a random floor number between 2 and 16 (some random numbers may be the same floor). Write a program to (i)) display the content of AX at base 2 (ii) use AX register to determine at which floors the elevator will stop.*/
short a = 12, b = 6, c;
void assembly() {
	_asm {
		mov ax, a;
		mov bx, b;
		and ax, bx;
		mov c, ax;
	}
	std::cout << c << std::endl;
}



#endif //!prob4_h