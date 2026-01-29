#include <QQhang.h>

class ExampleLayer : public QQhang::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//QQH_INFO("ExampleLayer::Update");
	}

	void OnEvent(QQhang::Event& event) override
	{
		QQH_TRACE("EXAMPLE LAYER ONEVENT: {0}", event.ToString());
	}

};

class GameDemo : public QQhang::Application {
public:
	GameDemo() {
		PushLayer(new ExampleLayer());
		PushOverlay(new QQhang::ImGuiLayer());
	}

	~GameDemo() {

	}

	void Run() {

	}
};

QQhang::Application* QQhang::CreateApplication() {
	return new GameDemo();
}