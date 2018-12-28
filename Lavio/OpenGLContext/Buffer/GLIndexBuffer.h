// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "../Source/Graphics/Buffers/IIndexBuffer.h"
#include "../OpenGLContext_Exports.h"

#include "../OpenGL.h"

namespace Lavio
{
	namespace OpenGL
	{
		namespace Graphics
		{
			class GLIndexBuffer : public Lavio::Graphics::IIndexBuffer
			{
			private:
				GLuint mBufferID;
				GLuint mCount;
			public:
				GL_API GLIndexBuffer(GLushort *data, GLsizei count);
				GL_API ~GLIndexBuffer();

				GL_API void Bind() const override;
				GL_API void Unbind() const override;

				GL_API unsigned int GetCount() const override
				{
					return mCount;
				}

				GL_API unsigned short* GetReadPointerForBuffer() const override
				{
					return static_cast<unsigned short*>(glMapBufferRange(GL_ELEMENT_ARRAY_BUFFER, 0, mCount, GL_MAP_READ_BIT));
				}

			private:
				GL_API GLIndexBuffer(const GLIndexBuffer& other);
			};
		}
	}
}
