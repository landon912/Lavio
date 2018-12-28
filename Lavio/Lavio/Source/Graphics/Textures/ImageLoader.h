// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "ImageData.h"
#include "../Source/LavioDefines.h"

struct FIBITMAP;

namespace Lavio
{
	namespace Graphics
	{
		class ImageLoader
		{
		public:
			static ImageData* LoadImageData(const char *path);
#if TEXTURE_DEBUG
			static void ImageLoader::DumpImageData(const FIBITMAP &bitmap, const int &width, const int &height);
#endif
		public:
			ImageLoader() = delete;
			ImageLoader(const ImageLoader &other) = delete;
			ImageLoader& operator=(const ImageLoader& rhs) = delete;
			~ImageLoader() = delete;
		};
	}
}
