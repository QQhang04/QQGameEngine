#include "pch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "QQhang/Platforms/OpenGL/OpenGLVertexArray.h"

namespace QQhang {

	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:    QQH_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::OpenGL:  return new OpenGLVertexArray();
		}
	}

}