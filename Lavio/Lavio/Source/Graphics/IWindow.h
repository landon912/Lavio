// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "../IO/Input/IInput.h"

namespace Lavio
{
	namespace Graphics
	{
		class IWindow
		{
		protected:
			const char *mTitle;
			int mWidth, mHeight;
			void *mRawWindow;
			bool mClosed;

			virtual bool Awake() = 0;
		public:
			IWindow(const char *name, int width, int height) : mTitle(name), mWidth(width), mHeight(height), mRawWindow(nullptr), mClosed(false), AssignedInputModule(nullptr)
			{
			}

			virtual ~IWindow()
			{
				//mRawWindow is cleaned up by glfwTerminate
				//mTitle is pure data
			}

			virtual bool Closed() const = 0;
			virtual void Clear() const = 0;
			virtual void Update() { AssignedInputModule->Update(); }
			
			virtual void SetSize(const int &width, const int &height)
			{
				mWidth = width;
				mHeight = height;
			}

			virtual int GetWidth() const
			{
				return mWidth;
			}

			virtual int GetHeight() const
			{
				return mHeight;
			}

			virtual void* GetWindow() const
			{
				return mRawWindow;
			}

			IO::IInput *AssignedInputModule;

		public:
			IWindow(const IWindow &other) = delete;
			IWindow& operator=(const IWindow& rhs) = delete;
		};
	}
}
