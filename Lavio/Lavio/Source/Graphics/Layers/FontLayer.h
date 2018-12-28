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

		class FontLayer : public Layer
		{
		public:
			FontLayer(IShader *shader);
			~FontLayer();

		public:
			FontLayer(const FontLayer& other) = delete;
			FontLayer& operator=(const FontLayer& other) = delete;
		};
	}
}
