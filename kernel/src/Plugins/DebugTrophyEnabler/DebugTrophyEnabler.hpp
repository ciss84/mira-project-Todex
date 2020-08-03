#pragma once
#include <Utils/IModule.hpp>
#include <Utils/Types.hpp>

namespace Mira
{
		namespace Plugins
		{
				class DebugTrophyEnabler : public Mira::Utils::IModule
				{
				public:
						DebugTrophyEnabler();
						virtual ~DebugTrophyEnabler();

						virtual const char* GetName() override { return "DebugTrophyEnabler"; }
						virtual bool OnLoad() override;
						virtual bool OnUnload() override;
						virtual bool OnSuspend() override;
						virtual bool OnResume() override;
				};
		}
}
