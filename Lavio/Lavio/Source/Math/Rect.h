// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

namespace Lavio
{
	namespace Math
	{
		template <typename T>
		struct Rect
		{
			Rect(const T &left, const T &right, const T &bottom, const T &top);

			T left, right, top, bottom;
		};
	}
}
