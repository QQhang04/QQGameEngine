#pragma once

#include "Core.h"

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


