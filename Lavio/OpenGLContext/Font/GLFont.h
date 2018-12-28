// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "../../Lavio/Source/Graphics/GUI/IFont.h"

#include "../OpenGLContext_Exports.h"
#include "../../FreeType/FreeType-GL/freetype-gl.h"

namespace Lavio
{
	namespace OpenGL
	{
		namespace Graphics
		{
			class GLFont : public Lavio::Graphics::IFont
			{
			private:
				texture_atlas_t *mFTAtlas;
				texture_font_t *mFTFont;
			public:
				GL_API GLFont(std::string name, std::string filePath, unsigned int size);
				GL_API GLFont(std::string name, std::string filePath, unsigned int size, unsigned int atlasSizeX, unsigned int atlasSizeY);
				GL_API ~GLFont();

				GL_API void* GetRawAtlasPointer() const override { return mFTAtlas; }
				GL_API void* GetRawFontPointer() const override { return mFTFont; }
				GL_API unsigned int GetID() const override { return mFTAtlas->id; }
			};
		}
	}
}
