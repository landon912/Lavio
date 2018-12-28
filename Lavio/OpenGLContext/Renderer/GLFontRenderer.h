// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once
#include "GLBatch2DRenderer.h"

namespace Lavio
{
	namespace OpenGL
	{
		namespace Graphics
		{
			class GLFontRenderer : public GLBatchRenderer2D
			{
			public:
				GL_API GLFontRenderer() {}
				GL_API ~GLFontRenderer() {}

				GL_API bool Submit(const Lavio::Graphics::Graphic &graphic) override;

			private:
				void SetupAtlas();
			};
		}
	}
}
