// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "Graphics/IWindow.h"
#include "Platform/APIManager.h"
#include "../../../Debug/Debugging/Log.h"
#include "Graphics/GUI/FontManager.h"

namespace Lavio
{
	class World
	{
	public:
		static World& CreateInstance(Graphics::IWindow *window, API::APIManager *APIManager)
		{
			try
			{
				if (!worldInstance)
				{
					worldInstance = new World(window, APIManager);
				}
				return (*worldInstance);
			}
			catch (...)
			{
				Log::DebugLog("World Error -> World Creation Failed");
				return (*worldInstance);
			}
		}

		static World& GetInstance()
		{
			if (!worldInstance)
			{
				Log::DebugLog("World Error -> Attempted to acess an invalid World");
			}
			return (*worldInstance);
		}

		static void DestroyInstance()
		{
			delete worldInstance;
		}

		~World();

		void LoadFontManager()
		{
			FontManager = new Graphics::FontManager();
		}

		Graphics::IWindow *Window;
		IO::IInput *Input;
		API::APIManager *APIManager;
		Graphics::FontManager *FontManager;
	private:
		static World *worldInstance;
		World(Graphics::IWindow *window, API::APIManager *api);
		void LoadInput();
	public:
		World(const World& other) = delete;
		World& operator=(const World& rhs) = delete;
	};
}