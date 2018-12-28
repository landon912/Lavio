// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#include "GLContext.h"
#include "OpenGL.h"
#include "../Debug/Debugging/Log.h"

namespace Lavio
{
	namespace OpenGL
	{
		void GLFWErrorCallback(int error, const char *description);

		void GLContext::Awake()
		{
			Log::DebugLog("Loaded GLContext");
			glfwSetErrorCallback(GLFWErrorCallback);
			glClearColor(0, 0.5, 1, 1);
			glActiveTexture(GL_TEXTURE0);
			
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		}

		void GLFWErrorCallback(int error, const char *description)
		{
			std::string *text = new std::string("GLFW Error -> ");
			text->append(std::to_string(error));
			text->append(description);
			Log::DebugLog(text, true);
		}
	}
}
