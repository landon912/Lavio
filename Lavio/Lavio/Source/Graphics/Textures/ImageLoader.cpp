// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#include "ImageLoader.h"
#include "../../../Debug/Debugging/Log.h"

#include <FreeImage.h>

namespace Lavio
{
	namespace Graphics
	{
		ImageData* ImageLoader::LoadImageData(const char *path)
		{
			FREE_IMAGE_FORMAT imageFormat = FIF_UNKNOWN;
			FIBITMAP *bitmap(nullptr);


			imageFormat = FreeImage_GetFileType(path, 0);
			if (imageFormat == FIF_UNKNOWN)
			{
				imageFormat = FreeImage_GetFIFFromFilename(path);
			}
			//if still unkown, return failure
			if (imageFormat == FIF_UNKNOWN)
			{
				Log::DebugLog("Error Loading Image -> Unable to deduce filetype");
				return nullptr;
			}

			if (FreeImage_FIFSupportsReading(imageFormat))
			{
				bitmap = FreeImage_Load(imageFormat, path);
			}
			//if the image failed to load, return failure
			if (!bitmap)
			{
				Log::DebugLog("Error Loading Image -> Bitmap failed to load");
				return nullptr;
			}

			BYTE *bits = FreeImage_GetBits(bitmap);
			unsigned int bitsPerPixel = FreeImage_GetBPP(bitmap);

			int width = FreeImage_GetWidth(bitmap);
			int height = FreeImage_GetHeight(bitmap);
			//if one of these failed (they shouldn't), return failure
			if ((bits == nullptr) || (width == 0) || (height == 0))
			{
				std::string *errorOutput = new std::string("Unknown Error Loading Image from " + *path);
				Log::DebugLog(errorOutput, true);
				return nullptr;
			}

#if TEXTURE_DEBUG
			DumpImageData(*bitmap, width, height);
#endif

			int size = width * height * (bitsPerPixel / 8);
			unsigned char* result = new unsigned char[size];
			memcpy(result, bits, size);

			FreeImage_Unload(bitmap);

			return new ImageData(result, width, height, bitsPerPixel, path);
		}

#if TEXTURE_DEBUG
		void ImageLoader::DumpImageData(const FIBITMAP &bitmap, const int &width, const int &height)
		{
			FREE_IMAGE_TYPE type = FreeImage_GetImageType(const_cast<FIBITMAP *>(&bitmap));

			//make new copy
			BYTE *localBits = FreeImage_GetBits(const_cast<FIBITMAP *>(&bitmap));

			unsigned int pitch = FreeImage_GetPitch(const_cast<FIBITMAP *>(&bitmap));

			if (type == FIT_BITMAP && FreeImage_GetBPP(const_cast<FIBITMAP *>(&bitmap)) == 32)
			{
				for (int y = 0; y < height; y++)
				{
					BYTE *pixel = reinterpret_cast<BYTE*>(localBits);
					for (int x = 0; x < width; x++)
					{
						std::cout << +pixel[FI_RGBA_RED] << " " << +pixel[FI_RGBA_GREEN] << " " << +pixel[FI_RGBA_BLUE] << " " << +pixel[FI_RGBA_ALPHA] << std::endl;
						pixel += 4;
					}
					localBits += pitch;
				}
			}
			else if(type == FIT_BITMAP && FreeImage_GetBPP(const_cast<FIBITMAP *>(&bitmap)) == 24)
			{
				for (int y = 0; y < height; y++)
				{
					BYTE *pixel = reinterpret_cast<BYTE*>(localBits);
					for (int x = 0; x < width; x++)
					{
						std::cout << +pixel[FI_RGBA_RED] << " " << +pixel[FI_RGBA_GREEN] << " " << +pixel[FI_RGBA_BLUE] << std::endl;
						pixel += 3;
					}
					localBits += pitch;
				}
			}
		}
#endif
	}
}
