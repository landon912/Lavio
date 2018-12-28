// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#include "../../Graphics/GUI/IFont.h"
#include "../RenderAPI.h"
#include "FontFactory.h"
#include "../../../../OpenGLContext/Font/GLFont.h"
#include "../../../Debug/Debugging/Log.h"

namespace Lavio
{
	namespace API
	{
		Graphics::IFont* FontFactory::CreateFont(RenderAPI api, std::string name, std::string filePath, unsigned size)
		{
			switch (api)
			{
			case RenderAPI::OpenGL:
				return new OpenGL::Graphics::GLFont(name, filePath, size);
			default:
				Log::DebugLog("Buffer Factory Error -> No Buffer Module for this API!");
				return nullptr;
			}
		}

		Graphics::IFont* FontFactory::CreateFont(RenderAPI api, std::string name, std::string filePath, unsigned size, unsigned atlasSizeX, unsigned atlasSizeY)
		{
			switch (api)
			{
			case RenderAPI::OpenGL:
				return new OpenGL::Graphics::GLFont(name, filePath, size, atlasSizeX, atlasSizeY);
			default:
				Log::DebugLog("Buffer Factory Error -> No Buffer Module for this API!");
				return nullptr;
			}
		}
	}
}
