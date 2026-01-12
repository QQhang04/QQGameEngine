#pragma once

#ifdef QQH_PLATFORM_WINDOWS

extern QQhang::Application* QQhang::CreateApplication();

int main(int argc, char** argv) {
	printf("qqhang engine\n");
	auto app = QQhang::CreateApplication();
	app->Run();
	delete app;
}
#endif // QQH_PLATFORM_WINDOWS
