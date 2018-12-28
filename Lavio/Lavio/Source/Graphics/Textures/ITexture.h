// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "ImageData.h"
#include "../Source/LavioDefines.h"

#if DEBUG_BUILD
	#include <iostream>
#endif

namespace Lavio
{
	namespace Graphics
	{
		class ITexture
		{
		protected:
			unsigned int mTextureID;
			const ImageData *mRawImageData;
		public:
			ITexture(const ImageData *rawImageData) : mTextureID(0), mRawImageData(rawImageData)
			{
			}

			virtual ~ITexture()
			{
				delete mRawImageData;
			}

			virtual void Bind() const = 0;
			virtual void Unbind() const = 0;

			unsigned int GetWidth() const
			{
				return mRawImageData->width;
			}

			unsigned int GetHeight() const
			{
				return mRawImageData->height;
			}

			unsigned int GetTextureID() const
			{
				return mTextureID;
			}

			const ImageData& GetImageData() const
			{
				return *mRawImageData;
			}

		private:
			virtual unsigned int Load() = 0;

		public:
			ITexture(const ITexture &other) = delete;
			ITexture& operator=(const ITexture& rhs) = delete;
		};
	}
}
