#pragma once

#include "Core.h"
#include "Events/Event.h"

#include "Events/ApplicationEvent.h"
#include "QQhang/LayerStack.h"

#include "QQhang/Window.h"

#include "QQhang/ImGui/ImGuiLayer.h"

#include "QQhang/Renderer/Shader.h"

namespace QQhang {
	class QQH_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;

		static Application* s_Instance;
		std::unique_ptr<Shader> m_Shader;
	};

	Application* CreateApplication();
}


