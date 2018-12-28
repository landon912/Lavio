// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "Layer.h"

namespace Lavio
{
	namespace Graphics
	{
		using namespace Math;

		class TileLayer : public Layer
		{
		public:
			TileLayer(IShader *shader);
			~TileLayer();

			TileLayer(const TileLayer& other) = delete;
			TileLayer& operator=(const TileLayer& other) = delete;
		};
	}
}
