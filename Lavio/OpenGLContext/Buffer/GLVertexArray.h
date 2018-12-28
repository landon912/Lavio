// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "GLBuffer.h"
#include "../Source/Graphics/Buffers/IVertexArray.h"

namespace Lavio
{
	namespace OpenGL
	{
		namespace Graphics
		{
			class GLVertexArray : public Lavio::Graphics::IVertexArray
			{
			private:
				GLuint mArrayID;
			public:
				GL_API GLVertexArray();
				GL_API ~GLVertexArray();

				GL_API void AddBuffer(Lavio::Graphics::IBuffer *buffer, unsigned int index, unsigned int stride);
				//GL_API void GetReadPointerForBuffer() const override;
				GL_API void Bind() const override;
				GL_API void Unbind() const override;

			private:
				GL_API GLVertexArray(const GLVertexArray& other);
			};
		}
	}
}
