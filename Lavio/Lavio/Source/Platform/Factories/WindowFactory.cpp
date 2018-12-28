// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#include "WindowFactory.h"
#include "../../OpenGLContext/Window/GLWindow.h"
#include "../../../../Debug/Debugging/Log.h"

namespace Lavio
{
	namespace API
	{
		using namespace Graphics;

		IWindow* WindowFactory::CreateLavioWindow(RenderAPI api, const char *name, int width, int height)
		{
			switch (api)
			{
				case RenderAPI::OpenGL:
					return new OpenGL::Graphics::GLWindow(name, width, height);
				default:
					Log::DebugLog("Window Factory Error -> No Window Module for this API!");
					return nullptr;
			}
		}
	}
}
