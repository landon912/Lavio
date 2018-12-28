// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#include "GLInput.h"
#include "../../Lavio/Source/Graphics/IWindow.h"
#include "../../Debug/Debugging/Log.h"

namespace Lavio
{
	namespace OpenGL
	{
		namespace IO
		{
			void GLInput::KeyCallback(GLFWwindow *glfwWindow, int key, int scancode, int action, int mods)
			{
				Graphics::IWindow *window = static_cast<Graphics::IWindow*>(glfwGetWindowUserPointer(glfwWindow));
				window->AssignedInputModule->EmulateKeyPress(key, action);
			}

			void GLInput::MouseCallback(GLFWwindow *glfwWindow, int button, int action, int mods)
			{
				Graphics::IWindow *window = static_cast<Graphics::IWindow*>(glfwGetWindowUserPointer(glfwWindow));
				window->AssignedInputModule->EmulateMouseButtonPress(button, action);
			}

			void GLInput::CursorPositionCallback(GLFWwindow *glfwWindow, double xPosition, double yPosition)
			{
				Graphics::IWindow *window = static_cast<Graphics::IWindow*>(glfwGetWindowUserPointer(glfwWindow));
				window->AssignedInputModule->SetMousePosition(xPosition, yPosition);
			}

			GLInput::GLInput()
			{
			}

			void GLInput::Update()
			{
				IInput::Update();
			}

			void GLInput::SetContextCallbacks(void *glfwWindow) const
			{
				glfwSetKeyCallback(static_cast<GLFWwindow*>(glfwWindow), KeyCallback);
				glfwSetCursorPosCallback(static_cast<GLFWwindow*>(glfwWindow), CursorPositionCallback);
				glfwSetMouseButtonCallback(static_cast<GLFWwindow*>(glfwWindow), MouseCallback);
				Log::DebugLog("Set Input Context Callbacks");
			}

			void GLInput::EmulateKeyPress(int keyIndex, int action)
			{
				mKeys[keyIndex] = (action != GLFW_RELEASE);
			}

			void GLInput::EmulateMouseButtonPress(int buttonIndex, int action)
			{
				mMouseButtons[buttonIndex] = (action != GLFW_RELEASE);
			}

			void GLInput::SetMousePosition(double x, double y)
			{
				mMouseX = x;
				mMouseY = y;
			}

			bool GLInput::IsKeyPressed(unsigned int keyIndex) const
			{
				return CheckKeyIndexRange(keyIndex, MAX_KEYS) ? mKeysPressed[keyIndex] : false;
			}

			bool GLInput::IsKeyDown(unsigned int keyIndex) const
			{
				return CheckKeyIndexRange(keyIndex, MAX_KEYS) ? mKeys[keyIndex] : false;
			}

			bool GLInput::IsMouseButtonPressed(unsigned int buttonIndex) const
			{
				return CheckKeyIndexRange(buttonIndex, MAX_BUTTONS) ? mMouseButtonsPressed[buttonIndex] : false;
			}

			bool GLInput::IsMouseButtonDown(unsigned int buttonIndex) const
			{
				return CheckKeyIndexRange(buttonIndex, MAX_BUTTONS) ? mMouseButtons[buttonIndex] : false;
			}

			Math::Vector2<double> GLInput::GetMousePosition() const
			{
				return Math::Vector2<double>(mMouseX, mMouseY);
			}
		}
	}
}
