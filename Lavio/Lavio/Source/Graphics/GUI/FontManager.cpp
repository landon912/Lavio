// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#include "FontManager.h"

#include "../../../Debug/Debugging/Log.h"
#include <sstream>
#include "../../Platform/Factories/FontFactory.h"
#include "../../World.h"

namespace Lavio
{
	namespace Graphics
	{
		FontManager::FontManager()
		{
			Add(API::FontFactory::CreateFont(World::GetInstance().APIManager->GetCurrentAPI(), "Error", ERROR_FONT_FILE_PATH, 16));
		}

		FontManager::~FontManager()
		{
			for (int i = 0; i < mFonts.size(); i++)
			{
				delete mFonts[i];
			}
		}

		void FontManager::Add(IFont* font)
		{
			mFonts.push_back(font);
		}

		IFont* FontManager::Get(const std::string& name)
		{
			for(IFont* font : mFonts)
			{
				if(font->GetName() == name)
				{
					return font;
				}
			}

			//return error font
			std::string* text = new std::string("Cannot find font - \"" + name + "\"");
			Log::DebugLog(text, true);

			return mFonts[0];
		}

		IFont* FontManager::Get(const std::string &name, unsigned int size)
		{
			for (IFont* font : mFonts)
			{
				if (font->GetSize() == size && font->GetName() == name)
				{
					return font;
				}
			}

			for(IFont* font : mFonts)
			{
				if(font->GetName() == name)
				{
					Add(API::FontFactory::CreateFont(World::GetInstance().APIManager->GetCurrentAPI(), font->GetName(), font->GetFilename(), size));
					return mFonts[mFonts.size() - 1];
				}
			}

			//return error font
			std::ostringstream sizeString;
			sizeString << int(size);
			std::string* text = new std::string("Cannot find font - \"" + name + "\" with size \"" + sizeString.str() + "\"");
			Log::DebugLog(text, true);

			return mFonts[0];
		}
	}
}
