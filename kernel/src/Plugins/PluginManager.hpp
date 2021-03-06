#pragma once
#include <Utils/IModule.hpp>
#include <Utils/Vector.hpp>

extern "C"
{
    #include <sys/param.h>
    #include <sys/mutex.h>
}

namespace Mira
{
    namespace Plugins
    {
        class PluginManager : public Mira::Utils::IModule
        {
        private:
            Vector<Mira::Utils::IModule*> m_Plugins;

        public:
            PluginManager();
            virtual ~PluginManager();

            virtual bool OnLoad() override;
            virtual bool OnUnload() override;
            virtual bool OnSuspend() override;
            virtual bool OnResume() override;
        private:
            Mira::Utils::IModule* m_Logger;
            Mira::Utils::IModule* m_LoggerConsole;
            Mira::Utils::IModule* m_Debugger;
            Mira::Utils::IModule* m_Debugger3;                       
            Mira::Utils::IModule* m_FileManager;
            Mira::Utils::IModule* m_FakeSelfManager;
            Mira::Utils::IModule* m_FakePkgManager;
            Mira::Utils::IModule* m_EmuRegistry;
            Mira::Utils::IModule* m_Substitute;
            Mira::Utils::IModule* m_BrowserActivator;
            Mira::Utils::IModule* m_MorpheusEnabler;
            Mira::Utils::IModule* m_RemotePlayEnabler;
            Mira::Utils::IModule* m_RemotePkgEnabler; 
            Mira::Utils::IModule* m_DebugTrophyEnabler;             
            Mira::Utils::IModule* m_SyscallGuard;
            Mira::Utils::IModule* m_TTYRedirector;

        public:
            Mira::Utils::IModule* GetLogger() { return m_Logger; }
            Mira::Utils::IModule* GetLoggerConsole() { return m_LoggerConsole; }
            Mira::Utils::IModule* GetDebugger() { return m_Debugger; }
            Mira::Utils::IModule* GetDebugger3() { return m_Debugger3; }            
            Mira::Utils::IModule* GetFakeSelfManager() { return m_FakeSelfManager; }
            Mira::Utils::IModule* GetFakePkgManager() { return m_FakePkgManager; }
            Mira::Utils::IModule* GetEmulatedRegistry() { return m_EmuRegistry; }
            Mira::Utils::IModule* GetSubstitute() { return m_Substitute; }
            Mira::Utils::IModule* GetBrowserActivator() { return m_BrowserActivator; }
            Mira::Utils::IModule* GetMorpheusEnabler() { return m_MorpheusEnabler; }
            Mira::Utils::IModule* GetRemotePlayEnabler() { return m_RemotePlayEnabler; }
            Mira::Utils::IModule* GetRemotePkgEnabler() { return m_RemotePkgEnabler; }
            Mira::Utils::IModule* GetDebugTrophyEnabler() { return m_DebugTrophyEnabler; }                                   
            Mira::Utils::IModule* GetSyscallGuard() { return m_SyscallGuard; }
            Mira::Utils::IModule* GetTTYRedirector() { return m_TTYRedirector; }
        };
    }
}
