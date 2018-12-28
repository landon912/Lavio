// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "../RenderAPI.h"

namespace Lavio
{
	namespace API
	{
		class FontFactory
		{
		public:
			static Graphics::IFont* CreateFont(RenderAPI api, std::string name, std::string filePath, unsigned int size);
			static Graphics::IFont* CreateFont(RenderAPI api, std::string name, std::string filePath, unsigned int size, unsigned int atlasSizeX, unsigned int atlasSizeY);
		public:
			FontFactory() = delete;
			FontFactory(const FontFactory& other) = delete;
			FontFactory& operator=(const FontFactory& rhs) = delete;
			~FontFactory() = delete;
		};
	}
}