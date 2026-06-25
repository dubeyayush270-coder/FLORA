#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace FLORA {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			FL_TRACE("{0}", e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			FL_TRACE("{0}", e.ToString());
		}

		while (true);
	}
}