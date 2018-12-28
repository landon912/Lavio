// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "../../Lavio/Source/Graphics/Textures/ITexture.h"
#include "../../Lavio/Source/Graphics/Textures/ImageData.h"
#include "../OpenGLContext_Exports.h"

#include <utility>

namespace Lavio
{
	namespace OpenGL
	{
		namespace Graphics
		{
			class GLTexture : public Lavio::Graphics::ITexture
			{
			public:
				GL_API GLTexture(const Lavio::Graphics::ImageData *rawImageData);
				GL_API ~GLTexture() { }

				GL_API GLTexture(const GLTexture &other) : ITexture(new Lavio::Graphics::ImageData(*other.mRawImageData))
				{
					mTextureID = other.mTextureID;
				}

				GL_API friend void swap(GLTexture& left, GLTexture& right)
				{
					using std::swap;

					swap(left.mRawImageData, right.mRawImageData);
				}

				GL_API GLTexture& operator=(GLTexture other)
				{
					swap(*this, other);
					return *this;
				}

				GL_API void Bind() const override;
				GL_API void Unbind() const override;
			private:
				GL_API unsigned int Load() override;
			};
		}
	}
}
