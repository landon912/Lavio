// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once
#include "ColorComponents.h"
#include "ColorSet.h"

namespace Lavio
{
	namespace Graphics
	{
		struct Color
		{
			static ColorSet Colors;

			const static unsigned int mMask;

		private:
			ColorComponents mColorComponents;
			unsigned int mPackedColor;

		public:
			Color()
			{
				mColorComponents.r = 0;
				mColorComponents.g = 0;
				mColorComponents.b = 0;
				mColorComponents.a = 255;

				PackColor();
			}

			Color(const int r, const int g, const int b, const int a)
			{
				SetColor(r, g, b, a);
			}

			Color(unsigned int packedColor)
			{
				SetColor(packedColor);
			}

			unsigned int GetPackedColor() const
			{
				return mPackedColor;
			}

			const ColorComponents& GetColorComponents() const
			{
				return mColorComponents;
			}

			void SetColor(int r, int g, int b, int a);

			void SetColor(unsigned int packedColor);

			void PackColor();

			void UnPackColor();
		
		public:
			Color(const Color& other);
			Color operator=(const Color& other);
		};
	}
}
