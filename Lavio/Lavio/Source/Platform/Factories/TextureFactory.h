// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "../RenderAPI.h"
#include "../Source/Graphics/Textures/ITexture.h"

namespace Lavio
{
	namespace Graphics
	{
		struct ImageData;
	}
}

namespace Lavio
{
	namespace API
	{
		class TextureFactory
		{
		public:
			static Graphics::ITexture* CreateTexture(RenderAPI api, const Graphics::ImageData *rawImageData);

		public:
			TextureFactory() = delete;
			TextureFactory(const TextureFactory& other) = delete;
			TextureFactory& operator=(const TextureFactory& rhs) = delete;
			~TextureFactory() = delete;
		};
	}
}
