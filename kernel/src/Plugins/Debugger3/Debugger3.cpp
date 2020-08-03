// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "Debugger3.hpp"
#include <Utils/Kdlsym.hpp>
#include <Utils/Logger.hpp>

#include <OrbisOS/Utilities.hpp>

using namespace Mira::Plugins;
using namespace Mira::OrbisOS;

extern "C"
{
	#include <sys/mman.h>
};

Debugger3::Debugger3()
{

}

Debugger3::~Debugger3()
{

}

bool Debugger3::OnLoad()
{
	WriteLog(LL_Debug, "patching SceShellCore");

	struct ::proc* s_Process = Utilities::FindProcessByName("SceShellCore");
	if (s_Process == nullptr)
	{
		WriteLog(LL_Error, "could not find SceShellCore");
		return false;
	}

	ProcVmMapEntry* s_Entries = nullptr;
	size_t s_NumEntries = 0;
	auto s_Ret = Utilities::GetProcessVmMap(s_Process, &s_Entries, &s_NumEntries);
	if (s_Ret < 0)
	{
		WriteLog(LL_Error, "could not get vm map");
		return false;
	}

	if (s_Entries == nullptr || s_NumEntries == 0)
	{
		WriteLog(LL_Error, "invalid entries (%p) or numEntries (%d)", s_Entries, s_NumEntries);
		return false;
	}

	uint8_t* s_TextStart = nullptr;
	for (auto i = 0; i < s_NumEntries; ++i)
	{
		if (s_Entries[i].prot == (PROT_READ | PROT_EXEC))
		{
			s_TextStart = (uint8_t*)s_Entries[i].start;
			break;
		}
	}

	if (s_TextStart == nullptr)
	{
		WriteLog(LL_Error, "could not find SceShellCore text start");
		return false;
	}

	WriteLog(LL_Debug, "SceShellCore .text: (%p)", s_TextStart);

	// Free the entries we got returned
	delete [] s_Entries;
	s_Entries = nullptr;
    #if MIRA_PLATFORM <= MIRA_PLATFORM_ORBIS_BSD_505
  
    s_Ret = Utilities::ProcessReadWriteMemory(s_Process, (void*)(s_TextStart + ssc_Patch_debug_settingA), 1, (void*) "\x14", nullptr, true);
    if (s_Ret < 0)
      {
        WriteLog(LL_Error, "ssc_Patch_debug_settingA");
        return false;
    }
    
    s_Ret = Utilities::ProcessReadWriteMemory(s_Process, (void*)(s_TextStart + ssc_Patch_debug_settingB), 1, (void*) "\3", nullptr, true);
    if (s_Ret < 0)
      {
        WriteLog(LL_Error, "ssc_Patch_debug_settingB");
        return false;
    }

    s_Ret = Utilities::ProcessReadWriteMemory(s_Process, (void*)(s_TextStart + ssc_Patch_debug_settingC), 1, (void*) "\1", nullptr, true);
    if (s_Ret < 0)
      {
        WriteLog(LL_Error, "ssc_Patch_debug_settingC");
        return false;
    } 
    
    s_Ret = Utilities::ProcessReadWriteMemory(s_Process, (void*)(s_TextStart + ssc_Patch_debug_settingD), 1, (void*) "\1", nullptr, true);
    if (s_Ret < 0)
      {
        WriteLog(LL_Error, "ssc_Patch_debug_settingD");
        return false;
    }
   
    s_Ret = Utilities::ProcessReadWriteMemory(s_Process, (void*)(s_TextStart + ssc_Patch_debug_settingE), 1, (void*) "\xC3", nullptr, true);
    if (s_Ret < 0)
      {
        WriteLog(LL_Error, "ssc_Patch_debug_settingE");
        return false;
    }
    
    s_Ret = Utilities::ProcessReadWriteMemory(s_Process, (void*)(s_TextStart + ssc_Patch_debug_settingF), 2, (void*) "\x90\x90", nullptr, true);
    if (s_Ret < 0)
      {
        WriteLog(LL_Error, "ssc_Patch_debug_settingF");
        return false;
    }
    
    s_Ret = Utilities::ProcessReadWriteMemory(s_Process, (void*)(s_TextStart + ssc_Patch_debug_settingG), 6, (void*) "\x90\x90\x90\x90\x90\x90", nullptr, true);
    if (s_Ret < 0)
      {
        WriteLog(LL_Error, "ssc_Patch_debug_settingG");
        return false;
    }
    
    s_Ret = Utilities::ProcessReadWriteMemory(s_Process, (void*)(s_TextStart + ssc_Fully_enable_Debug_SettingsA), 1, (void*) "\0", nullptr, true);
    if (s_Ret < 0)
      {
        WriteLog(LL_Error, "ssc_Fully_enable_Debug_SettingsA");
        return false;
    }
    
    s_Ret = Utilities::ProcessReadWriteMemory(s_Process, (void*)(s_TextStart + ssc_Fully_enable_Debug_SettingsB), 1, (void*) "\0", nullptr, true);
    if (s_Ret < 0)
      {
        WriteLog(LL_Error, "ssc_Fully_enable_Debug_SettingsB");
        return false;
    }
    
    /*s_Ret = Utilities::ProcessReadWriteMemory(s_Process, (void*)(s_TextStart + ssc_Fully_enable_Debug_SettingsC), 2, (void*) "\x81\x01", nullptr, true);
    if (s_Ret < 0)
      {
        WriteLog(LL_Error, "ssc_Fully_enable_Debug_SettingsC");
        return false;
    }*/
    
    s_Ret = Utilities::ProcessReadWriteMemory(s_Process, (void*)(s_TextStart + ssc_Fully_enable_Debug_SettingsD), 2, (void*) "\x90\x90", nullptr, true);
    if (s_Ret < 0)
      {
        WriteLog(LL_Error, "ssc_Fully_enable_Debug_SettingsD");
        return false;
    }
    
    s_Ret = Utilities::ProcessReadWriteMemory(s_Process, (void*)(s_TextStart + ssc_Fully_enable_Debug_SettingsE), 2, (void*) "\x90\x90", nullptr, true);
    if (s_Ret < 0)
      {
        WriteLog(LL_Error, "ssc_Fully_enable_Debug_SettingsE");
        return false;
    }
    
    s_Ret = Utilities::ProcessReadWriteMemory(s_Process, (void*)(s_TextStart + kdlsym_addr_pmap_PROTECT_P), 1, (void*) "\xEB", nullptr, true);
    if (s_Ret < 0)
      {
        WriteLog(LL_Error, "kdlsym_addr_pmap_PROTECT_P");
        return false;
    }
    
    s_Ret = Utilities::ProcessReadWriteMemory(s_Process, (void*)(s_TextStart + kdlsym_addr_pmap_PROTECT_P), 1, (void*) "\x75", nullptr, true);
    if (s_Ret < 0)
      {
        WriteLog(LL_Error, "kdlsym_addr_pmap_PROTECT_P");
        return false;
    }
    #endif    
	return true;
}

bool Debugger3::OnUnload()
{
	return true;
}

bool Debugger3::OnSuspend()
{
	return true;
}

bool Debugger3::OnResume()
{
	return true;
}