#include "types.h"
#include <Utils/Kernel.hpp>
#include <Utils/Kdlsym.hpp>
uint64_t __readmsr(unsigned long __register)
{
	unsigned long __edx;
	unsigned long __eax;
	__asm__ ("rdmsr" : "=d"(__edx), "=a"(__eax) : "c"(__register));
	return (((uint64_t)__edx) << 32) | (uint64_t)__eax;
}

void todex()
{
	uint8_t* kernel_base = (uint8_t*)(__readmsr(0xC0000082) - 0x1C0);
	//convert tid to dex
	*(unsigned char*)(kernel_base + 0x1BD800D) = 0x82;
	
}
int _main(void)
{
	return 0;
}