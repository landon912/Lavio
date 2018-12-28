// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "OpenGLContext_Exports.h"

namespace Lavio
{
	namespace OpenGL
	{
		class GLContext
		{
		public:
			GL_API static void Awake();

		private:
			GL_API GLContext() = delete;
			GL_API GLContext(const GLContext& other) = delete;
			GL_API GLContext& operator=(GLContext rhs) = delete;
			GL_API ~GLContext() = delete;
		};
	}
}
