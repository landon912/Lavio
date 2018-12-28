// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once
#include <vector>
#include "IFont.h"

#define ERROR_FONT_FILE_PATH "Manuscrit-Regular.ttf"

namespace Lavio
{
	namespace Graphics
	{
		class FontManager
		{
		private:
			std::vector<IFont*> mFonts;
		public:
			FontManager();
			~FontManager();

			void Add(IFont* font);
			IFont* Get(const std::string& name);
			IFont* Get(const std::string& name, unsigned int size);

		public:
			FontManager(const FontManager& other) = delete;
			FontManager& operator=(const FontManager& other) = delete;
		};
	}
}
