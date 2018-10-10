#pragma once
#pragma once
#ifndef prob3_h
#define prob3_h

using namespace std;

int counter = 0, arraycounter = 0;
int defective[16];
int y = 0X6a2f, t = 0, i2 = 17;
unsigned int c = 1 << 15;
int number = 0;
int j;

void getZero()
{
	cout << '0';
	defective[arraycounter] = i2 - 1;
}

void getOne()
{
	cout << '1';
}

void displayArray()
{
	cout << endl;
	cout << counter << " sprinklers are ON " << endl;
	cout << "Defective sprinklers: ";
}

void AXoutput()
{
	cout << "AX = ";
}

void outputNumber()
{
	cout << number << " ";
}
void MassonPark()
{
	__asm
	{
		call AXoutput;
	ForLoop:
		cmp		i2, 1;
		je		DisplayArray;
	Calculate:
		mov		eax, y;
		and		eax, c;
		mov		t, eax;
		cmp		t, 0;
		je		DisplayZero;
		call	getOne;
		inc		counter;
		dec		i2;
		mov		eax, y;
		shl		eax, 1;
		mov		y, eax;
		jmp		ForLoop;
	DisplayZero:
		call	getZero;
		dec		i2;
		inc		arraycounter;
		mov		eax, y;
		shl		eax, 1;
		mov		y, eax;
		jmp		ForLoop;
	DisplayArray:
		lea		esi, defective;
		call	displayArray;
	whileLoop:
		cmp		arraycounter, 0;
		je		Done;
		mov		ebx, [esi];
		mov		number, ebx;
		call	outputNumber;
		add		esi, 4;
		dec		arraycounter;
		jmp		whileLoop;
	Done:
	}
}

#endif // !PROGRAM_3
