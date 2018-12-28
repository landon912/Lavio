// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "../RenderAPI.h"
#include "../../Graphics/IWindow.h"

namespace Lavio
{
	namespace API
	{
		using namespace Graphics;

		class WindowFactory
		{
		public:
			static IWindow* CreateLavioWindow(RenderAPI api, const char *name, int width, int height);

		public:
			WindowFactory() = delete;
			WindowFactory(const WindowFactory& other) = delete;
			WindowFactory& operator=(const WindowFactory& rhs) = delete;
			~WindowFactory() = delete;
		};
	}
}
