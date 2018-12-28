// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#include "ShaderFactory.h"
#include "../../OpenGLContext/Shader/GLShader.h"
#include "../../../../Debug/Debugging/Log.h"

namespace Lavio
{
	namespace API
	{
		IShader* ShaderFactory::CreateShader(RenderAPI api, const char *vertPath, const char *fragPath)
		{
			switch (api)
			{
				case RenderAPI::OpenGL:
					return new OpenGL::Graphics::GLShader(vertPath, fragPath);
				default:
					Log::DebugLog("Shader Factory Error -> No Shader Module for this API!");
					return nullptr;
			}
		}
	}
}
