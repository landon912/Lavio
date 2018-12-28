// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

//#include "../stdafx.h"
#include "GLBuffer.h"

#include <glew.h>

namespace Lavio
{
	namespace OpenGL
	{
		namespace Graphics
		{
			GLBuffer::GLBuffer(GLfloat *data, GLsizei count, GLuint componentCount)
				: IBuffer()
			{
				mComponentCount = componentCount;

				glGenBuffers(1, &mBufferID);
				GLBuffer::Bind();
				glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
				GLBuffer::Unbind();
			}

			GLBuffer::~GLBuffer()
			{
				glDeleteBuffers(1, &mBufferID);
			}

			void GLBuffer::Bind() const
			{
				glBindBuffer(GL_ARRAY_BUFFER, mBufferID);
			}

			void GLBuffer::Unbind() const
			{
				glBindBuffer(GL_ARRAY_BUFFER, 0);
			}
		}
	}
}
