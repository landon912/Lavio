// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#include "BufferFactory.h"
#include "../../OpenGLContext/Buffer/GLBuffer.h"
#include "../../OpenGLContext/Buffer/GLIndexBuffer.h"
#include "../../OpenGLContext/Buffer/GLVertexArray.h"
#include "../../../Debug/Debugging/Log.h"

namespace Lavio
{
	namespace API
	{
		IBuffer* BufferFactory::CreateBuffer(RenderAPI api, float *data, int count, unsigned int componentCount)
		{
			switch (api)
			{
				case RenderAPI::OpenGL:
					return new OpenGL::Graphics::GLBuffer(static_cast<GLfloat*>(data), static_cast<GLsizei>(count), static_cast<GLuint>(componentCount));
				default:
					Log::DebugLog("Buffer Factory Error -> No Buffer Module for this API!");
					return nullptr;
			}
		}

		IIndexBuffer* BufferFactory::CreateIndexBuffer(RenderAPI api, unsigned short *data, int count)
		{
			switch (api)
			{
				case RenderAPI::OpenGL:

					return new OpenGL::Graphics::GLIndexBuffer(static_cast<GLushort*>(data), static_cast<GLsizei>(count));
				default:
					Log::DebugLog("Buffer Factory Error -> No IBO Module for this API!");
					return nullptr;
			}
		}

		IVertexArray* BufferFactory::CreateVertexArray(RenderAPI api)
		{
			switch (api)
			{
				case RenderAPI::OpenGL:
					return new OpenGL::Graphics::GLVertexArray();
				default:
					Log::DebugLog("Buffer Factory Error -> No VAO Module for this API!");
					return nullptr;
			}
		}
	}
}
