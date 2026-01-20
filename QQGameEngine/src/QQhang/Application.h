#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace QQhang {
	class QQH_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}


