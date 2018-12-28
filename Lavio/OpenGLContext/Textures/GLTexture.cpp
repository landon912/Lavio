// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#include "GLTexture.h"
#include "../OpenGL.h"

namespace Lavio
{
	namespace OpenGL
	{
		namespace Graphics
		{
			GLTexture::GLTexture(const Lavio::Graphics::ImageData *rawImageData)
				: ITexture(rawImageData)
			{
				if (rawImageData) 
				{
					mTextureID = GLTexture::Load();
				}
				else
				{
					mTextureID = 0;
				}
			}

			void GLTexture::Bind() const
			{
				glBindTexture(GL_TEXTURE_2D, mTextureID);
			}

			void GLTexture::Unbind() const
			{
				glBindTexture(GL_TEXTURE_2D, 0);
			}

			unsigned GLTexture::Load()
			{
				unsigned int result;

				glGenTextures(1, &result);
				glBindTexture(GL_TEXTURE_2D, result);

				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

				if (mRawImageData->bitsPerPixel == 32)
				{
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mRawImageData->width, mRawImageData->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, mRawImageData->pixelBytes);
				}
				else 
				{
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, mRawImageData->width, mRawImageData->height, 0, GL_RGB, GL_UNSIGNED_BYTE, mRawImageData->pixelBytes);
				}

				glBindTexture(GL_TEXTURE_2D, 0);

				return result;
			}
		}
	}
}
