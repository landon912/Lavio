// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "VectorMath.h"
#include "Matrix/Matrix4x4.cpp"
#include "Matrix/Matrix2x2.cpp"
#include "Rect.cpp"
#include <math.h>

template <typename T>
inline T ToRadians(T degrees)
{
	return T(degrees * (3.14159265358979323846 / static_cast<T>(180)));
}
