// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "../Graphic.h"
#include "IFont.h"

namespace Lavio
{
	namespace Graphics
	{
		namespace GUI
		{
			class Label : public Graphic
			{
			private:
				//Vector2<float> mOffset;
			public:
				std::string& text;
				IFont& font;
				Label(std::string &text, IFont& font, Color color, IShader& shader);
				Label(std::string &text, const std::string& fontName, unsigned int fontSize, Color color, IShader& shader);
				const std::string& GetText() const { return text; }

			public:
				Label(const Label& other) = delete;
				Label& operator=(const Label& other) = delete;
			};
		}
	}
}
