#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace FLORA {

	class FLORA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};
	// To be defined in CLIENT
	Application* CreateApplication();

}