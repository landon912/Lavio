// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "../../Math/Vector/Vector2.cpp"
#include "../../../../Debug/Debugging/Log.h"

namespace Lavio
{
	namespace IO
	{
#define MAX_KEYS 1024
#define MAX_BUTTONS 32

		class IInput
		{
		public:
			IInput(): mMouseX(0), mMouseY(0)
			{
				memset(mKeys, false, sizeof(bool)* MAX_KEYS);
				memset(mKeysLastFrame, false, sizeof(bool)* MAX_KEYS);
				memset(mKeysPressed, false, sizeof(bool)* MAX_KEYS);

				memset(mMouseButtons, false, sizeof(bool)* MAX_BUTTONS);
				memset(mMouseButtonsLastFrame, false, sizeof(bool)* MAX_BUTTONS);
				memset(mMouseButtonsPressed, false, sizeof(bool)* MAX_BUTTONS);

				Log::DebugLog("Created Input Module");
			}

			virtual ~IInput()
			{
			}

			virtual void Update()
			{
				for (int i = 0; i < MAX_KEYS; i++)
				{
					mKeysPressed[i] = mKeys[i] && !mKeysLastFrame[i];
				}
				memcpy(mKeysPressed, mKeys, sizeof(bool)*MAX_KEYS);
				
				for (int i = 0; i < MAX_BUTTONS; i++)
				{
					mMouseButtonsPressed[i] = mMouseButtons[i] && !mMouseButtonsLastFrame[i];
				}
				memcpy(mMouseButtonsLastFrame, mMouseButtons, sizeof(bool)*MAX_BUTTONS);
			}

			virtual void SetContextCallbacks(void *rawWindowContext) const = 0;
			virtual void EmulateKeyPress(int keyIndex, int action) = 0;
			virtual void EmulateMouseButtonPress(int buttonIndex, int action) = 0;
			virtual void SetMousePosition(double x, double y) = 0;
			virtual bool IsKeyPressed(unsigned int keyIndex) const = 0;
			virtual bool IsKeyDown(unsigned int keyIndex) const = 0;
			virtual bool IsMouseButtonPressed(unsigned int buttonIndex) const = 0;
			virtual bool IsMouseButtonDown(unsigned int buttonIndex) const = 0;
			virtual Math::Vector2<double> GetMousePosition() const = 0;

		protected:
			bool mKeys[MAX_KEYS];
			bool mKeysLastFrame[MAX_KEYS];
			bool mKeysPressed[MAX_KEYS];
			bool mMouseButtons[MAX_BUTTONS];
			bool mMouseButtonsLastFrame[MAX_BUTTONS];
			bool mMouseButtonsPressed[MAX_BUTTONS];
			double mMouseX, mMouseY;

			bool CheckKeyIndexRange(unsigned int keyIndex, unsigned int range) const
			{
				if (keyIndex >= range)
				{
					Log::DebugLog("Input Error -> Key is out of range!");
					return false;
				}
				return true;
			}
		};
	}
}
