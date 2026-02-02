#pragma once

#include "QQhang/Layer.h"

#include "QQhang/Events/ApplicationEvent.h"
#include "QQhang/Events/KeyEvent.h"
#include "QQhang/Events/MouseEvent.h"

namespace QQhang {
	class QQH_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};
}
