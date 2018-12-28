// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#include "Color.h"

#include <algorithm>

namespace Lavio
{
	namespace Graphics
	{		
		const unsigned int Color::mMask = (1 << 8) - 1;

		void Color::PackColor()
		{
			mPackedColor = mColorComponents.a << 24 | mColorComponents.b << 16 | mColorComponents.g << 8 | mColorComponents.r;
		}

		void Color::UnPackColor()
		{
			mColorComponents.r = mPackedColor & mMask;
			mColorComponents.g = mPackedColor >> 8 & mMask;
			mColorComponents.b = mPackedColor >> 16 & mMask;
			mColorComponents.a = mPackedColor >> 24 & mMask;
		}

		Color::Color(const Color &other)
		{
			mPackedColor = other.mPackedColor;
			mColorComponents.r = other.mColorComponents.r;
			mColorComponents.g = other.mColorComponents.g;
			mColorComponents.b = other.mColorComponents.b;
			mColorComponents.a = other.mColorComponents.a;
		}

		Color Color::operator=(const Color &other)
		{
			Color temp = Color(other);

			std::swap(mPackedColor, temp.mPackedColor);
			std::swap(mColorComponents.r, temp.mColorComponents.r);
			std::swap(mColorComponents.g, temp.mColorComponents.g);
			std::swap(mColorComponents.b, temp.mColorComponents.b);
			std::swap(mColorComponents.a, temp.mColorComponents.a);

			return *this;
		}

		/*Color Color::operator=(Color &other)
		{
			Color temp = Color(other);

			std::swap(mPackedColor, temp.mPackedColor);
			std::swap(mColorComponents.r, temp.mColorComponents.r);
			std::swap(mColorComponents.g, temp.mColorComponents.g);
			std::swap(mColorComponents.b, temp.mColorComponents.b);
			std::swap(mColorComponents.a, temp.mColorComponents.a);

			return *this;
		}*/

		void Color::SetColor(int r, int g, int b, int a)
		{
			mColorComponents.r = r;
			mColorComponents.g = g;
			mColorComponents.b = b;
			mColorComponents.a = a;

			PackColor();
		}

		void Color::SetColor(unsigned int packedColor)
		{
			mPackedColor = packedColor;

			UnPackColor();
		}
	}
}