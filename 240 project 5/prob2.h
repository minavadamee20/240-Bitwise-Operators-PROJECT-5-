#pragma once
#pragma once
#ifndef prob2_h
#define prob2_h
#include <iostream>
#include <string >

//using namespace std;
int i, total = 0, two = 2;
int	a[3] = { 0XBEEF, 0XFADE, 0XCABE };
std::string b[3] = { "BEEF", "FADE", "CABE" };

void outputEven()
{
	std::cout << b[i] << " is a valid ID for the family " << std::endl;
}

void oupuOdd()
{
	std::cout << b[i] << " is not valid ID for the family " << std::endl;
}
void pin()
{

	__asm
	{
		mov		eax, 0XF;
		mov		i, 0;
		lea		esi, a;
	forLoop:
		cmp		i, 3;
		je		Done;
		mov		ebx, [esi];
		shl		eax, 12;
		and		eax, ebx;
		shr		eax, 12;
		add		total, eax;
		mov		eax, 0XF;
		shl		eax, 8;
		and		eax, ebx;
		shr		eax, 8;
		add		total, eax;
		mov		eax, 0XF;
		shl		eax, 4;
		and		eax, ebx;
		shr		eax, 4;
		add		total, eax;
		mov		eax, 0XF;
		and		eax, ebx;
		add		total, eax;
		cdq;
		mov		eax, total;
		idiv	two;
		cmp		edx, 0;
		je		EvenNumber;
		call	oupuOdd;
		mov		eax, 0XF;
		mov		total, 0;
		add		esi, 4;
		inc		i;
		jmp		forLoop;
	EvenNumber:
		mov		ebx, 1b;
		call	outputEven;
		mov		eax, 0XF;
		mov		total, 0;
		add		esi, 4;
		inc		i;
		jmp		forLoop;

	Done:
	}

}

#endif // !PROGRAM_2