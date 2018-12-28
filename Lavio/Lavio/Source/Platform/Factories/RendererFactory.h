// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "../Source/Graphics/IRenderer2D.h"
#include "../RenderAPI.h"

namespace Lavio
{
	namespace API
	{
		using namespace Graphics;

		class RendererFactory
		{
		public:
			static IRenderer2D* Create2DRenderer(RenderAPI api, bool batching);
			static IRenderer2D* CreateFontRenderer(RenderAPI api);

		public:
			RendererFactory() = delete;
			RendererFactory(const RendererFactory& other) = delete;
			RendererFactory& operator=(const RendererFactory& rhs) = delete;
			~RendererFactory() = delete;
		};
	}
}
