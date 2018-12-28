// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

//#include "../stdafx.h"
#include "GLVertexArray.h"

namespace Lavio
{
	namespace OpenGL
	{
		namespace Graphics
		{
			GLVertexArray::GLVertexArray()
			{
				glGenVertexArrays(1, &mArrayID);
			}

			GLVertexArray::~GLVertexArray()
			{
				for (int i = 0; i < mBuffers.size(); i++)
				{
					delete mBuffers[i];
				}

				glDeleteVertexArrays(1, &mArrayID);
			}

			void GLVertexArray::AddBuffer(Lavio::Graphics::IBuffer *buffer, unsigned int index, unsigned int stride)
			{
				Bind();
				buffer->Bind();

				glEnableVertexAttribArray(static_cast<GLuint>(index));
				glVertexAttribPointer(static_cast<GLuint>(index), static_cast<GLint>(buffer->GetComponentCount()), GL_FLOAT, GL_FALSE, static_cast<GLuint>(stride), nullptr);

				buffer->Unbind();
				Unbind();

				mBuffers.push_back(buffer);
			}

			/*void GLVertexArray::GetReadPointerForBuffer() const
			{
				return glReadBuffer()
			}*/

			void GLVertexArray::Bind() const
			{
				glBindVertexArray(mArrayID);
			}

			void GLVertexArray::Unbind() const
			{
				glBindVertexArray(0);
			}
		}
	}
}
