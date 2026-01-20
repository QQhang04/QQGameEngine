#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace QQhang {
	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			QQH_TRACE(e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			QQH_TRACE(e.ToString());
		}
		while (true) {

		}
	}
}