#pragma once
#include <Utils/IModule.hpp>
#include <Utils/Types.hpp>

namespace Mira
{
		namespace Plugins
		{
				class Debugger3 : public Mira::Utils::IModule
				{
				public:
						Debugger3();
						virtual ~Debugger3();

						virtual const char* GetName() override { return "Debugger3"; }
						virtual bool OnLoad() override;
						virtual bool OnUnload() override;
						virtual bool OnSuspend() override;
						virtual bool OnResume() override;
				};
		}
}
