// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#include "GLFont.h"
#include "../../../Debug/Debugging/Log.h"

namespace Lavio
{
	namespace OpenGL
	{
		namespace Graphics
		{
			GLFont::GLFont(std::string name, std::string filePath, unsigned size)
				: GLFont(name, filePath, size, 512, 512)
			{
			}

			GLFont::GLFont(std::string name, std::string filePath, unsigned size, unsigned atlasSizeX, unsigned atlasSizeY)
				: IFont(size, name, filePath)
			{
				mFTAtlas = texture_atlas_new(atlasSizeX, atlasSizeY, 1);
				mFTFont = texture_font_new_from_file(mFTAtlas, 16, filePath.c_str());

				if(mFTFont == nullptr)
				{
					std::string* string = new std::string("Failed to load font \""  + name + "\" at filepath \"" + filePath + "\"");
					Log::DebugLog(string, LogVerbosity::DEBUG_ERROR, true);
				}

				texture_font_get_glyph(mFTFont, "0");
				texture_font_get_glyph(mFTFont, "1");
				texture_font_get_glyph(mFTFont, "2");
				texture_font_get_glyph(mFTFont, "3");
				texture_font_get_glyph(mFTFont, "4");
				texture_font_get_glyph(mFTFont, "5");
				texture_font_get_glyph(mFTFont, "6");
				texture_font_get_glyph(mFTFont, "7");
				texture_font_get_glyph(mFTFont, "8");
				texture_font_get_glyph(mFTFont, "9");
				texture_font_get_glyph(mFTFont, "F");
				texture_font_get_glyph(mFTFont, "P");
				texture_font_get_glyph(mFTFont, "S");
				texture_font_get_glyph(mFTFont, ":");
				texture_font_get_glyph(mFTFont, "H");
				texture_font_get_glyph(mFTFont, "E");
				texture_font_get_glyph(mFTFont, "L");
				texture_font_get_glyph(mFTFont, "O");
				texture_font_get_glyph(mFTFont, "!");
				texture_font_get_glyph(mFTFont, "L");
				texture_font_get_glyph(mFTFont, "S");
				texture_font_get_glyph(mFTFont, "R");

				glGenTextures(1, &mFTAtlas->id);
				glBindTexture(GL_TEXTURE_2D, mFTAtlas->id);
				//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
				//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, mFTAtlas->width, mFTAtlas->height,
					0, GL_ALPHA, GL_UNSIGNED_BYTE, mFTAtlas->data);
			}

			GLFont::~GLFont()
			{
				glDeleteTextures(1, &mFTAtlas->id);
				delete mFTAtlas;
				delete mFTFont;
			}
		}
	}
}