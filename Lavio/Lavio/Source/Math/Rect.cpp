// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "Rect.h"

namespace Lavio
{
	namespace Math
	{
		template <typename T>
		Rect<T>::Rect(const T &left, const T &right, const T &bottom, const T &top)
		{
			this->left = left;
			this->right = right;
			this->bottom = bottom;
			this->top = top;
		}
	}
}
