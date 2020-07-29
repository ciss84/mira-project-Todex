// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <Boot/Patches.hpp>

void Mira::Boot::Patches::install_prerunPatches_672()
{
#if MIRA_PLATFORM==MIRA_PLATFORM_ORBIS_BSD_672
	// You must assign the kernel base pointer before anything is done
	if (!gKernelBase)
		return;

	// Use "kmem" for all patches
	uint8_t *kmem;
	
	// Enable UART
	kmem = (uint8_t *)&gKernelBase[0x01A6EB18];
	kmem[0] = 0x00;
	
	// Verbose Panics
	kmem = (uint8_t *)&gKernelBase[0x002ED33A];
	kmem[0] = 0x90;
	kmem[1] = 0x90;
	kmem[2] = 0x90;
	kmem[3] = 0x90;
	kmem[4] = 0x90;
		
	// Patch dynlib_dlsym
	kmem = (uint8_t*)&gKernelBase[0x1D895A];
	kmem[0] = 0x90;
	kmem[1] = 0x90;
	kmem[2] = 0x90;
	kmem[3] = 0x90;
	kmem[4] = 0x90;
	kmem[5] = 0x90;

	// Patch a function called by dynlib_dlsym
	kmem = (uint8_t*)&gKernelBase[0x0041A2D0];
	kmem[0] = 0x31; // xor eax, eax
	kmem[1] = 0xC0; 
	kmem[2] = 0xC3;	// ret

	// Patch sys_mmap
	kmem = (uint8_t*)&gKernelBase[0x000AB57A];
	kmem[0] = 0x37; // mov     [rbp+var_61], 33h ; '3'
	kmem[3] = 0x37; // mov     sil, 33h ; '3'

	// patch sys_setuid
	kmem = (uint8_t*)&gKernelBase[0x0010BED0]; // call    priv_check_cred; overwrite with mov eax, 0
	kmem[0] = 0xB8; // mov eax, 0
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;
	kmem[4] = 0x00;

	// patch sys_mprotect
	kmem = (uint8_t*)&gKernelBase[0x00451DB8]; // jnz     loc_FFFFFFFF82652426; nop it out
	kmem[0] = 0x90;
	kmem[1] = 0x90;
	kmem[2] = 0x90;
	kmem[3] = 0x90;
	kmem[4] = 0x90;
	kmem[5] = 0x90;

	// Enable rwx mapping in kmem_alloc
	kmem = (uint8_t *)&gKernelBase[0x002507F5];
	kmem[0] = 0x07; // set maxprot to RWX

	kmem = (uint8_t *)&gKernelBase[0x00250803];
	kmem[0] = 0x07; // set maxprot to RWX

	// Patch copyin/copyout to allow userland + kernel addresses in both params
	// copyin
	kmem = (uint8_t *)&gKernelBase[0x003C17F7];
	kmem[0] = 0x90;
	kmem[1] = 0x90;

	kmem = (uint8_t *)&gKernelBase[0x003C1803];
	kmem[0] = 0x90;
	kmem[1] = 0x90;
	kmem[2] = 0x90;

	// copyout
	kmem = (uint8_t *)&gKernelBase[0x003C1702];
	kmem[0] = 0x90;
	kmem[1] = 0x90;

	kmem = (uint8_t *)&gKernelBase[0x003C170E];
	kmem[0] = 0x90;
	kmem[1] = 0x90;
	kmem[2] = 0x90;
	
	// Enable MAP_SELF
	kmem = (uint8_t *)&gKernelBase[0x00233C40];
	kmem[0] = 0xB8;
	kmem[1] = 0x01;
	kmem[2] = 0x00;
	kmem[3] = 0x00;
	kmem[4] = 0x00;
	kmem[5] = 0xC3;

	kmem = (uint8_t *)&gKernelBase[0x00233C50];
	kmem[0] = 0xB8;
	kmem[1] = 0x01;
	kmem[2] = 0x00;
	kmem[3] = 0x00;
	kmem[4] = 0x00;
	kmem[5] = 0xC3;

	kmem = (uint8_t *)&gKernelBase[0x000AD2E4];
	kmem[0] = 0x31;
	kmem[1] = 0xC0;
	kmem[2] = 0x90;
	kmem[3] = 0x90;
	kmem[4] = 0x90;
	
	// Patches: sceSblACMgrHasMmapSelfCapability
	kmem = (uint8_t *)&gKernelBase[0x00233C40];
	kmem[0] = 0xB8;
	kmem[1] = 0x01;
	kmem[2] = 0x00;
	kmem[3] = 0x00;
	kmem[4] = 0x00;
	kmem[5] = 0xC3;

	// Patches: sceSblACMgrIsAllowedToMmapSelf
	kmem = (uint8_t *)&gKernelBase[0x00233C50];
	kmem[0] = 0xB8;
	kmem[1] = 0x01;
	kmem[2] = 0x00;
	kmem[3] = 0x00;
	kmem[4] = 0x00;
	kmem[5] = 0xC3;

	// Patches: call    sceSblAuthMgrIsLoadable in vm_mmap2 (right above the only call to allowed to mmap self)
	kmem = (uint8_t *)&gKernelBase[0x000AD2E4]; // xor eax, eax; nop; nop;
	kmem[0] = 0x31;
	kmem[1] = 0xC0;
	kmem[2] = 0x90;
	kmem[3] = 0x90;
	kmem[4] = 0x90;

	// Patch copyinstr
	kmem = (uint8_t *)&gKernelBase[0x003C1CA3];
	kmem[0] = 0x90;
	kmem[1] = 0x90;

	kmem = (uint8_t *)&gKernelBase[0x003C1CAF];
	kmem[0] = 0x90;
	kmem[1] = 0x90;
	kmem[2] = 0x90;
	
	kmem = (uint8_t *)&gKernelBase[0x003C1857];
	kmem[0] = 0x41;
	kmem[1] = 0x41;
	
	// Patch memcpy stack
	kmem = (uint8_t *)&gKernelBase[0x003C15BD];
	kmem[0] = 0xEB;

	// ptrace patches
	kmem = (uint8_t *)&gKernelBase[0x0010F879];
	kmem[0] = 0xEB;

	// second ptrace patch
	kmem = (uint8_t *)&gKernelBase[0x0010FD02];
	kmem[0] = 0xEB;
	kmem[1] = 0x98;

	// setlogin patch (for autolaunch check)
	kmem = (uint8_t *)&gKernelBase[0x0010EC1C];
	kmem[0] = 0x48;
	kmem[1] = 0x31;
	kmem[2] = 0xC0;
	kmem[3] = 0x90;
	kmem[4] = 0x90;

	// Patch to remove vm_fault: fault on nofault entry, addr %llx
	kmem = (uint8_t *)&gKernelBase[0x000BC8F6];
	kmem[0] = 0x90;
	kmem[1] = 0x90;
	kmem[2] = 0x90;
	kmem[3] = 0x90;
	kmem[4] = 0x90;
	kmem[5] = 0x90;
	
	// Enable debug rif's
	kmem = (uint8_t*)&gKernelBase[0x66AEB0];
	kmem[0] = 0xB0; 
	kmem[1] = 0x01; 
	kmem[2] = 0xC3; 
	kmem[3] = 0x90;

	// Enable debug rifs 2
	kmem = (uint8_t*)&gKernelBase[0x66AEE0];
	kmem[0] = 0xB0; 
	kmem[1] = 0x01; 
	kmem[2] = 0xC3;
	kmem[3] = 0x90;

	// Disable pfs checks
	kmem = (uint8_t*)&gKernelBase[0x6A8EB0];
	kmem[0] = 0x31; 
	kmem[1] = 0xC0; 
	kmem[2] = 0xC3; 
	kmem[3] = 0x90;

	// disable delayed panics
	kmem = (uint8_t*)&gKernelBase[0x0063C8CE];
	kmem[0] = 0x90;
	kmem[1] = 0x90;

	kmem = (uint8_t*)kdlsym(global_settings_base);
	kmem[0x36] |= 0x14;
	kmem[0x59] |= 0x01; // sceSblRcMgrIsAllowULDebugger
	kmem[0x59] |= 0x02; // sceSblRcMgrIsAllowSLDebugger
	kmem[0x5A] |= 0x01;
	kmem[0x78] |= 0x01;

	// Disable this verif bullshit

	// Disable sceSblSysVeriResume
	kmem = (uint8_t*)&gKernelBase[0x0063CDB0];
	kmem[0] = 0xC3;
	kmem[1] = 0x90;
	kmem[2] = 0x90;

	// Disable sceSblSysVeriSuspend
	kmem = (uint8_t*)&gKernelBase[0x0063CC90];
	kmem[0] = 0xC3;
	kmem[1] = 0x90;
	kmem[2] = 0x90;

	// Disable sysvericheckstatus_maybe
	/*kmem = (uint8_t*)&gKernelBase[0x0063BD90];
	kmem[0] = 0xC3;
	kmem[1] = 0x90;
	kmem[2] = 0x90;

	// Disable sysvericheckstatus_maybe callout_ call
	kmem = (uint8_t*)&gKernelBase[0x0063BDE4];
	kmem[0] = 0x90;
	kmem[1] = 0x90;
	kmem[2] = 0x90;
	kmem[3] = 0x90;
	kmem[4] = 0x90;*/

	// Disable delayedPanicCb
	kmem = (uint8_t*)&gKernelBase[0x0063C8C0];
	kmem[0] = 0xC3;
	kmem[1] = 0x90;
	kmem[2] = 0x90;

	// Disable panic_fatal
	/*kmem = (uint8_t*)&gKernelBase[0x0043BB0];
	kmem[0] = 0xC3;
	kmem[1] = 0x90;
	kmem[2] = 0x90;*/

	// Disable sub_FFFFFFFF8283C8D1
	/*kmem = (uint8_t*)&gKernelBase[0x0063C8D1];
	kmem[0] = 0xC3;
	kmem[1] = 0x90;
	kmem[2] = 0x90;

	// NOP sled sceSblSysVeriThread
	kmem = (uint8_t*)&gKernelBase[0x0063C950];
	for (int i = 0; i < 0x327; ++i)
		kmem[i] = 0x90; // NOP sled the entire shit, until the kthread_exit call*/

	// Enable *all* debugging logs (in vprintf)
	// Patch by: SiSTRo
	kmem = (uint8_t *)&gKernelBase[0x00123367];
	kmem[0] = 0xEB;
	kmem[1] = 0x3B;
	
	// Patch by: JOGolden
	kmem = (uint8_t *)&gKernelBase[0x003C1AC2];
	kmem[0] = 0x90;
	kmem[1] = 0x90;

	kmem = (uint8_t *)&gKernelBase[0x003C1AD1];
	kmem[0] = 0x90;
	kmem[1] = 0x90;
	
	kmem = (uint8_t *)kdlsym(global_settings_base);
	kmem[0x36] |= 0x14;
	kmem[0x59] |= 0x01; // sceSblRcMgrIsAllowULDebugger
	kmem[0x59] |= 0x02; // sceSblRcMgrIsAllowSLDebugger
	kmem[0x5A] |= 0x01;
	kmem[0x78] |= 0x01;
	
// Patch debug setting errors
	kmem = (uint8_t *)&gKernelBase[0x00504A94];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;
	kmem = (uint8_t *)&gKernelBase[0x00504C77];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;	
  kmem = (uint8_t *)&gKernelBase[0x00507A01];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;
	kmem = (uint8_t *)&gKernelBase[0x00507B09];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;	
	kmem = (uint8_t *)&gKernelBase[0x00507BB8];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;
	kmem = (uint8_t *)&gKernelBase[0x00507ECF];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;	
	kmem = (uint8_t *)&gKernelBase[0x00508D5C];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;
	kmem = (uint8_t *)&gKernelBase[0x00510423];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;	
	kmem = (uint8_t *)&gKernelBase[0x005108E3];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;
	kmem = (uint8_t *)&gKernelBase[0x00510BFA];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;	
	kmem = (uint8_t *)&gKernelBase[0x005115E1];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;
	kmem = (uint8_t *)&gKernelBase[0x00511B4D];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;	
	kmem = (uint8_t *)&gKernelBase[0x00512002];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;
	kmem = (uint8_t *)&gKernelBase[0x00512191];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;	
	kmem = (uint8_t *)&gKernelBase[0x005140A8];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;
	kmem = (uint8_t *)&gKernelBase[0x00514293];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;	
	kmem = (uint8_t *)&gKernelBase[0x00515E71];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;
	kmem = (uint8_t *)&gKernelBase[0x00515EE7];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;	
	kmem = (uint8_t *)&gKernelBase[0x00515F71];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;
	kmem = (uint8_t *)&gKernelBase[0x00515F8D];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;	
	kmem = (uint8_t *)&gKernelBase[0x0051F123];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;
		
// Firmware spoof sdk reverse 01007206 to 01005107
  kmem = (uint8_t *)&gKernelBase[0x0044C79B];
  kmem[0] = 0x01;
  kmem[1] = 0x00;
  kmem[2] = 0x00;
  kmem[3] = 0x08;
  kmem = (uint8_t *)&gKernelBase[0x0044D719];
  kmem[0] = 0x01;
  kmem[1] = 0x00;
  kmem[2] = 0x00;
  kmem[3] = 0x08;
  kmem = (uint8_t *)&gKernelBase[0x0044D7BA];
  kmem[0] = 0x01;
  kmem[1] = 0x00;
  kmem[2] = 0x00;
  kmem[3] = 0x08;
  kmem = (uint8_t *)&gKernelBase[0x00666158];
  kmem[0] = 0x01;
  kmem[1] = 0x00;
  kmem[2] = 0x00;
  kmem[3] = 0x08;
  kmem = (uint8_t *)&gKernelBase[0x006A9DB2];
  kmem[0] = 0x01;
  kmem[1] = 0x00;
  kmem[2] = 0x00;
  kmem[3] = 0x08;
  kmem = (uint8_t *)&gKernelBase[0x0077A5B4];
  kmem[0] = 0x01;
  kmem[1] = 0x00;
  kmem[2] = 0x00;
  kmem[3] = 0x08;
  kmem = (uint8_t *)&gKernelBase[0x0078315D];
  kmem[0] = 0x01;
  kmem[1] = 0x00;
  kmem[2] = 0x00;
  kmem[3] = 0x08;
  kmem = (uint8_t *)&gKernelBase[0x01A84248];
  kmem[0] = 0x01;
  kmem[1] = 0x00;
  kmem[2] = 0x00;
  kmem[3] = 0x08;
  kmem = (uint8_t *)&gKernelBase[0x022C0718];
  kmem[0] = 0x01;
  kmem[1] = 0x00;
  kmem[2] = 0x00;
  kmem[3] = 0x08;
  kmem = (uint8_t *)&gKernelBase[0x02926C81];
  kmem[0] = 0x01;
  kmem[1] = 0x00;
  kmem[2] = 0x00;
  kmem[3] = 0x08;  
// Firmware spoof sdk 07000 to 08500
  kmem = (uint8_t *)&gKernelBase[0x027A8303];
  kmem[0] = 0x30;
  kmem[1] = 0x38;
  kmem[2] = 0x35;
  kmem[3] = 0x30;
  kmem[4] = 0x30;
  kmem = (uint8_t *)&gKernelBase[0x027F773E];
  kmem[0] = 0x30;
  kmem[1] = 0x38;
  kmem[2] = 0x35;
  kmem[3] = 0x30;
  kmem[4] = 0x30; 
  // Firmware spoof sdk 06720001 to 08000001
  kmem = (uint8_t *)&gKernelBase[0x027E089E];
  kmem[0] = 0x30;
  kmem[1] = 0x38;
  kmem[2] = 0x30;
  kmem[3] = 0x30;
  kmem[4] = 0x30;
  kmem[5] = 0x30;
  kmem[6] = 0x30;
  kmem[7] = 0x31;
  kmem = (uint8_t *)&gKernelBase[0x027E08C5];
  kmem[0] = 0x30;
  kmem[1] = 0x38;
  kmem[2] = 0x30;
  kmem[3] = 0x30;
  kmem[4] = 0x30;
  kmem[5] = 0x30;
  kmem[6] = 0x30;
  kmem[7] = 0x31;
  kmem = (uint8_t *)&gKernelBase[0x027E1ABC];
  kmem[0] = 0x30;
  kmem[1] = 0x38;
  kmem[2] = 0x30;
  kmem[3] = 0x30;
  kmem[4] = 0x30;
  kmem[5] = 0x30;
  kmem[6] = 0x30;
  kmem[7] = 0x31;
  // Firmware spoof release Day to Fri jul 18  
  kmem = (uint8_t *)&gKernelBase[0x01540008];
  kmem[0] = 0x40;
  kmem[1] = 0x72;
  kmem[2] = 0x69;
  kmem[3] = 0x20;
  kmem[4] = 0x6A;
  kmem[5] = 0x75;
  kmem[6] = 0x6C;
  kmem[7] = 0x20;
  kmem[8] = 0x31;
  kmem[9] = 0x38;
  // Firmware spoof release branches r157870/release_branches/release_07.510 May 31 2020 15:07:40
  kmem = (uint8_t *)&gKernelBase[0x01540080];
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