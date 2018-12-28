// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#include "Label.h"
#include "../GUI/FontManager.h"
#include "../../World.h"

namespace Lavio
{
	namespace Graphics
	{
		namespace GUI
		{
			Label::Label(std::string &text, IFont& font, Color color, IShader& shader)
				: Graphic(true, Vector2<float>(1,1), color, shader), text(text), font(font) {

			}

			Label::Label(std::string &text, const std::string &font, unsigned int fontSize, Color color, IShader &shader)
				: Graphic(true, Vector2<float>(1, 1), color, shader), text(text), font(*World::GetInstance().FontManager->Get(font, fontSize))
			{
			}
		}
	}
}
