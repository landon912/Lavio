// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include <algorithm>

namespace Lavio
{
	namespace Graphics
	{
		struct ImageData
		{
			ImageData(unsigned char *pixelBytes, unsigned width, unsigned height, unsigned int bitsPerPixel, const char *path)
				:	pixelBytes(pixelBytes),
					width(width),
					height(height),
					bitsPerPixel(bitsPerPixel),
					path(path)
			{
			}

			//TODO: Make TextureManager and delete this
			ImageData(const ImageData& other): width(other.width), height(other.height), bitsPerPixel(other.bitsPerPixel)
			{
				pixelBytes = new unsigned char[width * height] {*other.pixelBytes};
				path = new char(*other.path);
			}

			~ImageData()
			{
				delete pixelBytes;
			}

			const unsigned char *pixelBytes;
			const unsigned int width, height; 
			const unsigned int bitsPerPixel;
			const char *path;

		public:
			ImageData& operator=(const ImageData& other) = delete;
		};
	}
}
