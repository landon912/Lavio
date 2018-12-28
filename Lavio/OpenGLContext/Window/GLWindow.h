// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "../Source/Graphics/IWindow.h"
#include "../OpenGL.h"
#include "../OpenGLContext_Exports.h"

namespace Lavio
{
	namespace OpenGL
	{
		namespace Graphics
		{
			class GLWindow : public Lavio::Graphics::IWindow
			{
			protected:
				GLFWwindow *mContextWindow;
				bool Awake() override;
			public:
				GL_API GLWindow(const char *name, int width, int height);
				virtual GL_API ~GLWindow();
				GL_API bool Closed() const override;
				GL_API void Clear() const override;
				GL_API void Update() override;
				

				GL_API int GetWidth() const override
				{
					return mWidth;
				}

				GL_API int GetHeight() const override
				{
					return mHeight;
				}

				GL_API void* GetWindow() const override
				{
					return mRawWindow;
				}

				IO::IInput *AssignedInputModule;

			private:
				GL_API GLWindow(const GLWindow& other) = delete;
				static GL_API void WindowResizedCallback(GLFWwindow *window, int width, int height);
			};
		}
	}
}
