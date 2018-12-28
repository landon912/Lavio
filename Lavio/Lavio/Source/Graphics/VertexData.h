// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "../Math/VectorMath.h"

namespace Lavio
{
	namespace Graphics
	{
		using namespace Math;

		//per vertex data
		struct VertexData
		{
			Vector3<float> vertex; //4 byte alignment * 3
			Vector2<float> uv; //4 byte alignment * 2
			float textureID; //4 byte alignment
			unsigned int color; //4 byte alignment
			//unsigned char pad[0];
		};
	}
}
