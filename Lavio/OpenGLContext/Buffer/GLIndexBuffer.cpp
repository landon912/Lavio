// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#include "GLIndexBuffer.h"

namespace Lavio
{
	namespace OpenGL
	{
		//need ability to write back data
		namespace Graphics
		{
			GLIndexBuffer::GLIndexBuffer(GLushort *data, GLsizei count)
				: IIndexBuffer()
			{
				mCount = count;

				glGenBuffers(1, &mBufferID);
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mBufferID);
				glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLushort), data, GL_STATIC_DRAW);
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			}

			GLIndexBuffer::~GLIndexBuffer()
			{
				glDeleteBuffers(1, &mBufferID);
			}

			void GLIndexBuffer::Bind() const
			{
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mBufferID);
			}

			void GLIndexBuffer::Unbind() const
			{
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			}
		}
	}
}
