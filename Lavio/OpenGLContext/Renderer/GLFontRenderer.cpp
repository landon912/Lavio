// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#include "GLFontRenderer.h"
#include "../Source/Objects/GameObject.h"
#include "../Source/Graphics/Graphic.h"
#include "../Source/Graphics/GUI/Label.h"

namespace Lavio
{
	namespace OpenGL
	{
		namespace Graphics
		{
			bool GLFontRenderer::Submit(const Lavio::Graphics::Graphic &graphic)
			{
				using namespace ftgl;

				const Component* component = dynamic_cast<const Component*>(&graphic);

				const Lavio::Graphics::GUI::Label* label = dynamic_cast<const Lavio::Graphics::GUI::Label*>(&graphic);

				const Matrix4x4<float> &matrix = component->GetParentGameObject().GetTransform().GetTransformationMatrix();

				unsigned int color = label->GetColor().GetPackedColor();

				const Lavio::Graphics::IFont &font = label->font;

				//opengl doesn't like ints too much
				float textureSlot = 0.0f;

				bool found = false;

				//search for texture already assigned to sampler
				for (unsigned int i = 0; i < mTextureSlots.size(); i++)
				{
					if (mTextureSlots[i] == font.GetID())
					{
						found = true;
						textureSlot = static_cast<float>(i + 1);
						break;
					}
				}

				if (!found)
				{
					if (mTextureSlots.size() >= 32)
					{
						SplitDrawCall();
					}

					mTextureSlots.push_back(font.GetID());
					textureSlot = static_cast<float>(mTextureSlots.size());
				}

				float scaleX = 1080.0f / 32.0f;
				float scaleY = 640.0f / 32.0f;
				float offsetX = component->GetParentGameObject().GetTransform().GetPosition(false).x;
				float offsetY = component->GetParentGameObject().GetTransform().GetPosition(false).y;

				for (int i = 0; i < label->GetText().length(); i++)
				{
					const char& c = label->GetText()[i];
					texture_glyph_t* glyph = texture_font_get_glyph(static_cast<texture_font_t*>(font.GetRawFontPointer()), &c);

					if (glyph != nullptr)
					{
						if (i > 0)
						{
							float kerning = texture_glyph_get_kerning(glyph, &label->GetText()[i - 1]);
							offsetX += kerning / scaleX;
						}


						float x0 = offsetX + glyph->offset_x / scaleX;
						float y0 = offsetY + glyph->offset_y / scaleY;
						float x1 = x0 + glyph->width / scaleX;
						// - since our projection is postive y up
						float y1 = y0 - glyph->height / scaleY;

						float u0 = glyph->s0;
						float v0 = glyph->t0;
						float u1 = glyph->s1;
						float v1 = glyph->t1;

						mBuffer->vertex = matrix * Vector3<float>(x0, y0, 0);
						mBuffer->uv = Vector2<float>(u0, v0);
						mBuffer->textureID = textureSlot;
						mBuffer->color = color;
						mBuffer++;

						mBuffer->vertex = matrix * Vector3<float>(x0, y1, 0);
						mBuffer->uv = Vector2<float>(u0, v1);
						mBuffer->textureID = textureSlot;
						mBuffer->color = color;
						mBuffer++;

						mBuffer->vertex = matrix * Vector3<float>(x1, y1, 0);
						mBuffer->uv = Vector2<float>(u1, v1);
						mBuffer->textureID = textureSlot;
						mBuffer->color = color;
						mBuffer++;

						mBuffer->vertex = matrix * Vector3<float>(x1, y0, 0);
						mBuffer->uv = Vector2<float>(u1, v0);
						mBuffer->textureID = textureSlot;
						mBuffer->color = color;
						mBuffer++;

						offsetX += glyph->advance_x / scaleX;
						offsetY += glyph->advance_y / scaleY;
						mIndexCount += 6;
					}
				}

				return true;
			}

			void GLFontRenderer::SetupAtlas()
			{
				

				/*texture_font_get_glyph(mFTFont, "0");
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
				texture_font_get_glyph(mFTFont, "R");*/
			}
		}
	}
}