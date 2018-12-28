// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "../RenderAPI.h"
#include "../Source/Graphics/IShader.h"

namespace Lavio
{
	namespace API
	{
		using namespace Graphics;

		class ShaderFactory
		{
		public:
			static IShader* CreateShader(RenderAPI api, const char *vertPath, const char *fragPath);

		public:
			ShaderFactory() = delete;
			ShaderFactory(const ShaderFactory& other) = delete;
			ShaderFactory& operator=(const ShaderFactory& rhs) = delete;
			~ShaderFactory() = delete;
		};
	}
}
