#pragma once

#ifdef QQH_PLATFORM_WINDOWS

extern QQhang::Application* QQhang::CreateApplication();

int main(int argc, char** argv) {
	QQhang::Log::Init();
	QQH_CORE_INFO("Engine Log System Initialized!");
	QQH_INFO("Hello!");

	auto app = QQhang::CreateApplication();
	app->Run();
	delete app;
}
#endif // QQH_PLATFORM_WINDOWS
