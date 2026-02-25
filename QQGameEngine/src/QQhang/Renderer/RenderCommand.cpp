#include "pch.h"
#include "RenderCommand.h"

#include "QQhang/Platforms/OpenGL/OpenGLRendererAPI.h"

namespace QQhang {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}