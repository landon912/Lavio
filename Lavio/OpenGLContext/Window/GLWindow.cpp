// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "GLWindow.h"
#include "../GLContext.h"
#include "../../Debug/Debugging/Log.h"

namespace Lavio
{
	namespace OpenGL
	{
		namespace Graphics
		{
			GLWindow::GLWindow(const char *title, int width, int height)
				: IWindow(title, width, height)
			{
				if (GLWindow::Awake() == false)
				{
					glfwTerminate();
				}
			}

			GLWindow::~GLWindow()
			{
				glfwTerminate();
			}

			bool GLWindow::Awake()
			{
				std::string *text = new std::string(std::to_string(GetWidth()));
				text->append(",").append(std::to_string(GetHeight()));
				Log::DebugLog(text, true);

				if (!glfwInit())
				{
					Log::DebugLog("Window Error -> Failed to Awake GLFW");
					return false;
				}

				Log::DebugLog("Loaded GLFW");

				mRawWindow = glfwCreateWindow(mWidth, mHeight, mTitle, nullptr, nullptr);
				mContextWindow = static_cast<GLFWwindow*>(mRawWindow);

				if (!mRawWindow)
				{
					glfwTerminate();
					Log::DebugLog("Window Error -> Failed to create GLFW window!");
					return false;
				}

				glfwMakeContextCurrent(mContextWindow);

				glfwSetWindowUserPointer(mContextWindow, this);

				glfwSetFramebufferSizeCallback(mContextWindow, WindowResizedCallback);

				glfwSwapInterval(0);

				if (glewInit() != GLEW_OK)
				{
					Log::DebugLog("Window Error -> Could not load GLEW!");
					return false;
				}

				Log::DebugLog("Loaded GLEW");

				text = new std::string("OpenGL ");
				text->append(reinterpret_cast<const char*>(glGetString(GL_VERSION)));

				Log::DebugLog(text, true);

				GLContext::Awake();

				return true;
			}

			bool GLWindow::Closed() const
			{
				return glfwWindowShouldClose(mContextWindow) == 1;
			}

			void GLWindow::Clear() const
			{
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			}

			void GLWindow::Update()
			{
				IWindow::Update();

				GLenum error = glGetError();
				if (error != GL_NO_ERROR)
				{
					std::string *text = new std::string("OpenGL Error -> ");
					text->append(std::to_string(error));
					Log::DebugLog(text, true);
				}

				glfwPollEvents();
				glfwSwapBuffers(mContextWindow);
			}

			void GLWindow::WindowResizedCallback(GLFWwindow *window, int width, int height)
			{
				glViewport(0, 0, width, height);
				static_cast<GLWindow*>(glfwGetWindowUserPointer(window))->SetSize(width, height);

				Log::DebugLog(new std::string("Window Resized: " + std::to_string(width) + "," + std::to_string(height)), LogVerbosity::DEBUG_INFO ,true);
			}
		}
	}
}
