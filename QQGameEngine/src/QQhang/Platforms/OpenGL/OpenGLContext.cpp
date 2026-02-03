#include "pch.h"
#include "OpenGLContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

QQhang::OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
	: m_WindowHandle(windowHandle)
{
	QQH_CORE_ASSERT(windowHandle, "Window handle is null!");
}

void QQhang::OpenGLContext::Init()
{
	glfwMakeContextCurrent(m_WindowHandle);
	int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	QQH_CORE_ASSERT(status, "Failed to initialize Glad!");
}

void QQhang::OpenGLContext::SwapBuffers()
{
	glfwSwapBuffers(m_WindowHandle);
}
