// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#include "TextureFactory.h"
#include "../../OpenGLContext/Textures/GLTexture.h"
#include "../../Graphics/Textures/ImageData.h"
#include "../../Debug/Debugging/Log.h"


namespace Lavio
{
	namespace API
	{
		Graphics::ITexture* TextureFactory::CreateTexture(RenderAPI api, const Graphics::ImageData *rawImageData)
		{
			switch (api)
			{
				case RenderAPI::OpenGL:
					return new OpenGL::Graphics::GLTexture(rawImageData);
				default:
					Log::DebugLog("Texture Factory Error -> No Texture Module for this API!");
					return nullptr;
			}
		}
	}
}
