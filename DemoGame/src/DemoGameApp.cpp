#include <QQhang.h>

#include "imgui/imgui.h"

class ExampleLayer : public QQhang::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		/*auto [x, y] = QQhang::Input::GetMousePosition();
		QQH_INFO("ExampleLayer's mouse position: {0}, {1}", x, y);*/
	}

	void OnEvent(QQhang::Event& event) override
	{
		if (event.GetEventType() == QQhang::EventType::KeyPressed)
		{
			QQhang::KeyPressedEvent& e = (QQhang::KeyPressedEvent&)event;
			if (e.GetKeyCode() == QQH_KEY_TAB)
				QQH_TRACE("Tab key is pressed (event)!");
			QQH_TRACE("{0}", (char)e.GetKeyCode());
		}
	}

	virtual void OnImGuiRender() override
	{
		/*ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();*/
	}

};

class GameDemo : public QQhang::Application {
public:
	GameDemo() {
		PushLayer(new ExampleLayer());
	}

	~GameDemo() {

	}

	void Run() {

	}
};

QQhang::Application* QQhang::CreateApplication() {
	return new GameDemo();
}