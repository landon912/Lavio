// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#include "InputFactory.h"
#include "../../OpenGLContext/Input/GLInput.h"
#include "../../../Debug/Debugging/Log.h"

namespace Lavio
{
	namespace API
	{
		IO::IInput* InputFactory::CreateInput(RenderAPI api)
		{
			switch (api)
			{
				case RenderAPI::OpenGL:
					return new OpenGL::IO::GLInput();
				default:
					Log::DebugLog("Input Factory Error -> No Input Module for this API!");
					return nullptr;
			}
		}
	}
}
