// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <Boot/Patches.hpp>

/*
	Please, please, please!
	Keep patches consistent with the used patch style for readability.
*/
void Mira::Boot::Patches::install_prerunPatches_505()
{
#if MIRA_PLATFORM == MIRA_PLATFORM_ORBIS_BSD_505
	// You must assign the kernel base pointer before anything is done
	if (!gKernelBase)
		return;

	// Use "kmem" for all patches
	uint8_t *kmem;

	// Enable UART
	kmem = (uint8_t *)&gKernelBase[0x019ECEB0];
	kmem[0] = 0x00;

	// Verbose Panics
	kmem = (uint8_t *)&gKernelBase[0x00171627];
	kmem[0] = 0x90;
	kmem[1] = 0x90;
	kmem[2] = 0x90;
	kmem[3] = 0x90;
	kmem[4] = 0x90;

	// sceSblACMgrIsAllowedSystemLevelDebugging
	kmem = (uint8_t *)&gKernelBase[0x00010FC0];
	kmem[0] = 0xB8;
	kmem[1] = 0x01;
	kmem[2] = 0x00;
	kmem[3] = 0x00;
	kmem[4] = 0x00;
	kmem[5] = 0xC3;

	kmem = (uint8_t *)&gKernelBase[0x00011730];
	kmem[0] = 0xB8;
	kmem[1] = 0x01;
	kmem[2] = 0x00;
	kmem[3] = 0x00;
	kmem[4] = 0x00;
	kmem[5] = 0xC3;

	kmem = (uint8_t *)&gKernelBase[0x00011750];
	kmem[0] = 0xB8;
	kmem[1] = 0x01;
	kmem[2] = 0x00;
	kmem[3] = 0x00;
	kmem[4] = 0x00;
	kmem[5] = 0xC3;

	// Enable rwx mapping
	kmem = (uint8_t *)&gKernelBase[0x000FCD48];
	kmem[0] = 0x07;

	kmem = (uint8_t *)&gKernelBase[0x000FCD56];
	kmem[0] = 0x07;

	// Patch copyin/copyout to allow userland + kernel addresses in both params
	kmem = (uint8_t *)&gKernelBase[0x001EA767];
	kmem[0] = 0x90;
	kmem[1] = 0x90;

	kmem = (uint8_t *)&gKernelBase[0x001EA682];
	kmem[0] = 0x90;
	kmem[1] = 0x90;

	// Enable MAP_SELF
	kmem = (uint8_t *)&gKernelBase[0x000117B0];
	kmem[0] = 0xB8;
	kmem[1] = 0x01;
	kmem[2] = 0x00;
	kmem[3] = 0x00;
	kmem[4] = 0x00;
	kmem[5] = 0xC3;

	kmem = (uint8_t *)&gKernelBase[0x000117C0];
	kmem[0] = 0xB8;
	kmem[1] = 0x01;
	kmem[2] = 0x00;
	kmem[3] = 0x00;
	kmem[4] = 0x00;
	kmem[5] = 0xC3;

	kmem = (uint8_t *)&gKernelBase[0x0013F03F];
	kmem[0] = 0x31;
	kmem[1] = 0xC0;
	kmem[2] = 0x90;
	kmem[3] = 0x90;
	kmem[4] = 0x90;

	// Patch copyinstr
	kmem = (uint8_t *)&gKernelBase[0x001EAB93];
	kmem[0] = 0x90;
	kmem[1] = 0x90;

	kmem = (uint8_t *)&gKernelBase[0x001EABC3];
	kmem[0] = 0x90;
	kmem[1] = 0x90;

	// Patch memcpy stack
	kmem = (uint8_t *)&gKernelBase[0x001EA53D];
	kmem[0] = 0xEB;

	// ptrace patches, thx 2much4u
	kmem = (uint8_t *)&gKernelBase[0x0030D9AA];
	kmem[0] = 0xEB;

	// second ptrace patch, thx golden
	kmem = (uint8_t *)&gKernelBase[0x0030DE01];
	kmem[0] = 0xE9;
	kmem[1] = 0xD0;
	kmem[2] = 0x00;
	kmem[3] = 0x00;
	kmem[4] = 0x00;

	// setlogin patch (for autolaunch check)
	kmem = (uint8_t *)&gKernelBase[0x0005775C];
	kmem[0] = 0x48;
	kmem[1] = 0x31;
	kmem[2] = 0xC0;
	kmem[3] = 0x90;
	kmem[4] = 0x90;

	// Patch to remove vm_fault: fault on nofault entry, addr %llx
	kmem = (uint8_t *)&gKernelBase[0x002A4EB3];
	kmem[0] = 0x90;
	kmem[1] = 0x90;
	kmem[2] = 0x90;
	kmem[3] = 0x90;
	kmem[4] = 0x90;
	kmem[5] = 0x90;

	// patch mprotect to allow RWX (mprotect) mapping 5.05
	kmem = (uint8_t *)&gKernelBase[0x001A3C08];
	kmem[0] = 0x90;
	kmem[1] = 0x90;
	kmem[2] = 0x90;
	kmem[3] = 0x90;
	kmem[4] = 0x90;
	kmem[5] = 0x90;

	// flatz disable pfs signature check
	kmem = (uint8_t *)&gKernelBase[0x006A2700];
	kmem[0] = 0x31;
	kmem[1] = 0xC0;
	kmem[2] = 0xC3;

	// flatz enable debug RIFs
	kmem = (uint8_t *)&gKernelBase[0x0064B2B0];
	kmem[0] = 0xB0;
	kmem[1] = 0x01;
	kmem[2] = 0xC3;

	kmem = (uint8_t *)&gKernelBase[0x0064B2D0];
	kmem[0] = 0xB0;
	kmem[1] = 0x01;
	kmem[2] = 0xC3;

	// Enable *all* debugging logs (in vprintf)
	// Patch by: SiSTRo
	kmem = (uint8_t *)&gKernelBase[0x0043612A];
	kmem[0] = 0xEB;
	kmem[1] = 0x38;
	
	// flatz allow mangled symbol in dynlib_do_dlsym
	kmem = (uint8_t *)&gKernelBase[0x002AFB47];
  kmem[0] = 0x90;
	kmem[1] = 0x90;
	kmem[2] = 0x90;
	kmem[3] = 0x90;
	kmem[4] = 0x90;
	kmem[5] = 0x90;
		
	// Enable mount for unprivileged user
	kmem = (uint8_t *)&gKernelBase[0x001DEBFE];
	kmem[0] = 0x90;
	kmem[1] = 0x90;
	kmem[2] = 0x90;
	kmem[3] = 0x90;
	kmem[4] = 0x90;
	kmem[5] = 0x90;

	// patch suword_lwpid
	// has a check to see if child_tid/parent_tid is in kernel memory, and it in so patch it
	// Patch by: JOGolden
	kmem = (uint8_t *)&gKernelBase[0x001EA9D2];
	kmem[0] = 0x90;
	kmem[1] = 0x90;

	kmem = (uint8_t *)&gKernelBase[0x001EA9E1];
	kmem[0] = 0x90;
	kmem[1] = 0x90;
		
  kmem = (uint8_t *)&gKernelBase[0x00000190];
  kmem[0] = 0x2F;
  kmem[1] = 0x44;
  kmem[2] = 0x55;
  kmem[3] = 0x4D;
  kmem[4] = 0x4D;
  kmem[5] = 0x59;
  kmem[6] = 0x00;
  kmem[7] = 0xE8;
  kmem[8] = 0xF4;
  kmem[9] = 0x5A;
  kmem[10] = 0x73;
	
	// Patch debug setting errors RETAIL
	kmem = (uint8_t *)&gKernelBase[0x004F5B15];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;
	
	kmem = (uint8_t *)&gKernelBase[0x004F5E4A];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;
		
	kmem = (uint8_t *)&gKernelBase[0x004F8F51];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;
	
	kmem = (uint8_t *)&gKernelBase[0x004F9048];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;
	
	kmem = (uint8_t *)&gKernelBase[0x004F90EA];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;
	
	kmem = (uint8_t *)&gKernelBase[0x004F941D];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;
	
	kmem = (uint8_t *)&gKernelBase[0x004FA15C];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;

	kmem = (uint8_t *)&gKernelBase[0x00501439];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;

	kmem = (uint8_t *)&gKernelBase[0x0050191A];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;
	
	kmem = (uint8_t *)&gKernelBase[0x00501C3A];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;

	kmem = (uint8_t *)&gKernelBase[0X005026E0];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;

	kmem = (uint8_t *)&gKernelBase[0x00502776];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;

	kmem = (uint8_t *)&gKernelBase[0x00502AA6];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;

	kmem = (uint8_t *)&gKernelBase[0x00502C27];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;

	kmem = (uint8_t *)&gKernelBase[0x00504BB4];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;
	
	kmem = (uint8_t *)&gKernelBase[0x00504DAC];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;

	kmem = (uint8_t *)&gKernelBase[0X00506A2A];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;

	kmem = (uint8_t *)&gKernelBase[0x00506B91];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;

	kmem = (uint8_t *)&gKernelBase[0x00506C89];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;

	kmem = (uint8_t *)&gKernelBase[0x00506D11];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;

	kmem = (uint8_t *)&gKernelBase[0x0050D403];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;
					
	// prtinf hook patches
	kmem = (uint8_t *)&gKernelBase[0x00436136];
	kmem[0] = 0xEB;
	kmem[1] = 0x1E;

	kmem = (uint8_t *)&gKernelBase[0x00436154];
	kmem[0] = 0x90;
	kmem[1] = 0x90;
	
  // Firmware spoof sdk reverse 31000505 to 7.51
  kmem = (uint8_t *)&gKernelBase[0x0019EBC9];
  kmem[0] = 0x31;
  kmem[1] = 0x00;
  kmem[2] = 0x51;
  kmem[3] = 0x07;
  kmem = (uint8_t *)&gKernelBase[0x0019FB57];
  kmem[0] = 0x31;
  kmem[1] = 0x00;
  kmem[2] = 0x51;
  kmem[3] = 0x07;
  kmem = (uint8_t *)&gKernelBase[0x0019FBEA];
  kmem[0] = 0x31;
  kmem[1] = 0x00;
  kmem[2] = 0x51;
  kmem[3] = 0x07;
  kmem = (uint8_t *)&gKernelBase[0x00648C27];
  kmem[0] = 0x31;
  kmem[1] = 0x00;
  kmem[2] = 0x51;
  kmem[3] = 0x07;
  kmem = (uint8_t *)&gKernelBase[0x006A3636];
  kmem[0] = 0x31;
  kmem[1] = 0x00;
  kmem[2] = 0x51;
  kmem[3] = 0x07;
  kmem = (uint8_t *)&gKernelBase[0x0075B412];
  kmem[0] = 0x31;
  kmem[1] = 0x00;
  kmem[2] = 0x51;
  kmem[3] = 0x07;
  kmem = (uint8_t *)&gKernelBase[0x0076654F];
  kmem[0] = 0x31;
  kmem[1] = 0x00;
  kmem[2] = 0x51;
  kmem[3] = 0x07;
  kmem = (uint8_t *)&gKernelBase[0x01AA52D0];
  kmem[0] = 0x31;
  kmem[1] = 0x00;
  kmem[2] = 0x51;
  kmem[3] = 0x07;
  kmem = (uint8_t *)&gKernelBase[0x014A63F0];
  kmem[0] = 0x31;
  kmem[1] = 0x00;
  kmem[2] = 0x51;
  kmem[3] = 0x07;
  // Firmware spoof sdk 05508000 to 08008000
  kmem = (uint8_t *)&gKernelBase[0x02866078];
  kmem[0] = 0x30;
  kmem[1] = 0x38;
  kmem[2] = 0x30;
  kmem[3] = 0x30;
  kmem[4] = 0x38;
  kmem[5] = 0x30;
  kmem[6] = 0x30;
  kmem[7] = 0x30;
  kmem = (uint8_t *)&gKernelBase[0x0289718B];
  kmem[0] = 0x30;
  kmem[1] = 0x38;
  kmem[2] = 0x30;
  kmem[3] = 0x30;
  kmem[4] = 0x38;
  kmem[5] = 0x30;
  kmem[6] = 0x30;
  kmem[7] = 0x30; 
// Firmware spoof sdk 05050000 to 07510000
  kmem = (uint8_t *)&gKernelBase[0x02866090];
  kmem[0] = 0x30;
  kmem[1] = 0x37;
  kmem[2] = 0x35;
  kmem[3] = 0x31;
  kmem[4] = 0x30;
  kmem[5] = 0x30;
  kmem[6] = 0x30;
  kmem[7] = 0x30;
  kmem = (uint8_t *)&gKernelBase[0x028971A3];
  kmem[0] = 0x30;
  kmem[1] = 0x37;
  kmem[2] = 0x35;
  kmem[3] = 0x31;
  kmem[4] = 0x30;
  kmem[5] = 0x30;
  kmem[6] = 0x30;
  kmem[7] = 0x30;
// Firmware spoof version 05050001 to 07510001
  kmem = (uint8_t *)&gKernelBase[0x00005178];
  kmem[0] = 0x07;
  kmem[1] = 0x51;
  kmem[2] = 0x00;
  kmem[3] = 0x01;
  kmem = (uint8_t *)&gKernelBase[0x0000565F];
  kmem[0] = 0x07;
  kmem[1] = 0x51;
  kmem[2] = 0x00;
  kmem[3] = 0x01;
  kmem = (uint8_t *)&gKernelBase[0x000056FA];
  kmem[0] = 0x07;
  kmem[1] = 0x51;
  kmem[2] = 0x00;
  kmem[3] = 0x01;
  kmem = (uint8_t *)&gKernelBase[0x00842AE1];
  kmem[0] = 0x07;
  kmem[1] = 0x51;
  kmem[2] = 0x00;
  kmem[3] = 0x01;
  kmem = (uint8_t *)&gKernelBase[0x00897211];
  kmem[0] = 0x07;
  kmem[1] = 0x51;
  kmem[2] = 0x00;
  kmem[3] = 0x01;
  kmem = (uint8_t *)&gKernelBase[0x008E2A01];
  kmem[0] = 0x07;
  kmem[1] = 0x51;
  kmem[2] = 0x00;
  kmem[3] = 0x01;
// Firmware spoof version 00000505 reverse to 00005107  
  kmem = (uint8_t *)&gKernelBase[0x00063E5EF];
  kmem[0] = 0x00;
  kmem[1] = 0x00;
  kmem[2] = 0x51;
  kmem[3] = 0x07;
  kmem = (uint8_t *)&gKernelBase[0x000926122];
  kmem[0] = 0x00;
  kmem[1] = 0x00;
  kmem[2] = 0x51;
  kmem[3] = 0x07;
  kmem = (uint8_t *)&gKernelBase[0x0025199F4];
  kmem[0] = 0x00;
  kmem[1] = 0x00;
  kmem[2] = 0x51;
  kmem[3] = 0x07;
  kmem = (uint8_t *)&gKernelBase[0x0064CEB80];
  kmem[0] = 0x00;
  kmem[1] = 0x00;
  kmem[2] = 0x51;
  kmem[3] = 0x07; 
// Firmware spoof release Day to Fri May 31  
  kmem = (uint8_t *)&gKernelBase[0x00149C008];
  kmem[0] = 0x40;
  kmem[1] = 0x72;
  kmem[2] = 0x69;
  kmem[3] = 0x20;
  kmem[4] = 0x4D;
  kmem[5] = 0x61;
  kmem[6] = 0x79;
  kmem[7] = 0x20;
  kmem[8] = 0x33;
  kmem[9] = 0x31;
// Firmware spoof release branches r157870/release_branches/release_07.510 May 31 2020 15:07:40
  kmem = (uint8_t *)&gKernelBase[0x00149C080];
  kmem[0] = 0x72;
  kmem[1] = 0x31;
  kmem[2] = 0x35;
  kmem[3] = 0x37;
  kmem[4] = 0x38;
  kmem[5] = 0x37;
  kmem[6] = 0x30;
  kmem[7] = 0x2F;
  kmem[8] = 0x72;
  kmem[9] = 0x65;
  kmem[10] = 0x6C;
  kmem[11] = 0x65;
  kmem[12] = 0x61;
  kmem[13] = 0x73;
  kmem[14] = 0x65;
  kmem[15] = 0x5F;
  kmem[16] = 0x62;
  kmem[17] = 0x72;
  kmem[18] = 0x61;
  kmem[19] = 0x6E;
  kmem[20] = 0x63;
  kmem[21] = 0x68;
  kmem[22] = 0x65;
  kmem[23] = 0x73;
  kmem[24] = 0x2F;
  kmem[25] = 0x72;
  kmem[26] = 0x65;
  kmem[27] = 0x6C;
  kmem[28] = 0x65;
  kmem[29] = 0x61;
  kmem[30] = 0x73;
  kmem[31] = 0x65;
  kmem[32] = 0x5F;
  kmem[33] = 0x30;
  kmem[34] = 0x37;
  kmem[35] = 0x2E;
  kmem[36] = 0x35;
  kmem[37] = 0x31;
  kmem[38] = 0x30;
  kmem[39] = 0x20;
  kmem[40] = 0x4D;
  kmem[41] = 0x61;
  kmem[42] = 0x79;
  kmem[43] = 0x20;
  kmem[44] = 0x33;
  kmem[45] = 0x31;
  kmem[46] = 0x20;
  kmem[47] = 0x32;
  kmem[48] = 0x30;
  kmem[49] = 0x32;
  kmem[50] = 0x30;
  kmem[51] = 0x20;
  kmem[52] = 0x31;
  kmem[53] = 0x35;
  kmem[54] = 0x3A;
  kmem[55] = 0x30;
  kmem[56] = 0x37;
  kmem[57] = 0x3A;
  kmem[58] = 0x34;
  kmem[59] = 0x30;

#endif
}