#pragma once
#ifndef prob4_h
#define prob4_h
#include <iostream>
/*The sSheaton Hotel is a 16th floor building. Suppose each bits of AX register represent one floor (the right most bit is representing the first floor). Ten people got into the elevator on the first floor 
and each pressed a random floor number between 2 and 16 (some random numbers may be the same floor). Write a program to (i)) display the content of AX at base 2 (ii) use AX register to determine at which floors the elevator will stop.*/



short a[16];
short i4;
int AXvalue;
int t = 0, i5 = 1;
unsigned int c = 1 << 15;
short num;
short counter_for_Array = 0;
void displayMessage()
{
	cout << endl;
	cout << "Elevator will stop at floors no: ";
}

void displayArray1()
{
	cout << num << " ";
}

void getZero()
{
	cout << '0';
}
void getOne()
{
	cout << '1';
}

void outputFirstLine()
{
	cout << "AX = ";
}

void elevator()
{
	__asm
	{
		mov		ax, 1001000100001100b;
		movzx	eax, ax;
		mov		AXvalue, eax;
		lea		esi, a;
		mov		i4, 0;
		mov		bx, 1b;
	forLoop:
		cmp		i4, 16;
		je		printValue;
		mov		cx, i4;
		shl		bx, cl;
		and		bx, ax;
		shr		bx, cl;
		cmp		bx, 1;
		je		IsOne;
		inc		i4;
		mov		bx, 1b;
		jmp		forLoop;
	IsOne:
		inc		i4;
		inc		counter_for_Array;
		mov		dx, i4;
		mov[esi], dx;
		add		esi, 2;
		jmp		forLoop;

	printValue:
		call	outputFirstLine;
	ForLoop1:
		cmp		i5, 16;
		jg		DisplayArray;
	Calculate:
		mov		eax, AXvalue;
		and		eax, c;
		mov		t, eax;
		cmp		t, 0;
		je		DisplayZero;
		call	getOne;
		inc		i5;
		mov		eax, AXvalue;
		shl		eax, 1;
		mov		AXvalue, eax;
		jmp		ForLoop1;
	DisplayZero:
		call	getZero;
		inc		i5;
		mov		eax, AXvalue;
		shl		eax, 1;
		mov		AXvalue, eax;
		jmp		ForLoop1;
	DisplayArray:
		call	displayMessage;
		mov		i5, 0;
		lea		esi, a;
	whileLoop:
		cmp		counter_for_Array, 0;
		je		Done;
		mov		bx, [esi];
		add		esi, 2;
		mov		num, bx;
		call	displayArray1;
		inc		i5;
		dec		counter_for_Array;
		jmp		whileLoop;
	Done:


	}
}
#endif //!prob4_h