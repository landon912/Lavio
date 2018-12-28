// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "../Source/Graphics/Buffers/IBuffer.h"
#include "../OpenGLContext_Exports.h"

#include "../OpenGL.h"

namespace Lavio
{
	namespace OpenGL
	{
		namespace Graphics
		{
			class GLBuffer : public Lavio::Graphics::IBuffer
			{
			private:
				GLuint mBufferID;
				GLuint mComponentCount;
			public:
				GL_API GLBuffer(GLfloat *data, GLsizei count, GLuint componentCount);
				GL_API ~GLBuffer();

				GL_API void Bind() const override;
				GL_API void Unbind() const override;

				GL_API unsigned int GetComponentCount() const override
				{
					return mComponentCount;
				}

			private:
				GL_API GLBuffer(const GLBuffer& other);
			};
		}
	}
}
