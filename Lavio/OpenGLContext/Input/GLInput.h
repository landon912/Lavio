// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "../Source/IO/Input/IInput.h"
#include "../OpenGLContext_Exports.h"

#include "../OpenGL.h"

namespace Lavio
{
	namespace OpenGL
	{
		namespace IO
		{
#define MAX_KEYS 1024
#define MAX_BUTTONS 32

			class GLInput : public Lavio::IO::IInput
			{
			public:
				GL_API GLInput();

				virtual GL_API ~GLInput()
				{
				}

				GL_API void Update() override;

				GL_API void SetContextCallbacks(void *glfwWindow) const override;
				GL_API void EmulateKeyPress(int keyIndex, int action) override;
				GL_API void EmulateMouseButtonPress(int buttonIndex, int action) override;
				GL_API void SetMousePosition(double x, double y) override;
				GL_API bool IsKeyPressed(unsigned int keyIndex) const override;
				GL_API bool IsKeyDown(unsigned int keyIndex) const override;
				GL_API bool IsMouseButtonPressed(unsigned int buttonIndex) const override;
				GL_API bool IsMouseButtonDown(unsigned int buttonIndex) const override;
				GL_API Math::Vector2<double> GetMousePosition() const override;
			protected:
				static GL_API void KeyCallback(GLFWwindow *contextWindow, int key, int scancode, int action, int mods);
				static GL_API void MouseCallback(GLFWwindow *contextWindow, int key, int action, int mods);
				static GL_API void CursorPositionCallback(GLFWwindow *contextWindow, double xPosition, double yPosition);

			private:
				GL_API GLInput(const GLInput& other);
			};
		}
	}
}
