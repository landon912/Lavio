// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "../Source/Graphics/IRenderer2D.h"
#include "../Buffer/GLIndexBuffer.h"
#include "../Source/Math/Vector/Vector4.h"
#include "../../Lavio/Source/Graphics/VertexData.h"

#include <vector>
#include "../../FreeType/FreeType-GL/freetype-gl.h"

namespace Lavio
{
	namespace OpenGL
	{
		namespace Graphics
		{
#define RENDERER_MAX_GRAPHICS	10000
#define RENDERER_VERTEX_SIZE	(sizeof(Lavio::Graphics::VertexData))
#define RENDERER_GRAPHIC_SIZE	(RENDERER_VERTEX_SIZE * 4)
#define RENDERER_BUFFER_SIZE	(RENDERER_GRAPHIC_SIZE * RENDERER_MAX_GRAPHICS)
#define RENDERER_INDICES_SIZE	(RENDERER_MAX_GRAPHICS * 6)

#define SHADER_VERTEX_INDEX 0
#define SHADER_UV_INDEX 1
#define SHADER_TID_INDEX 2
#define SHADER_COLOR_INDEX 3

			class GLBatchRenderer2D : public Lavio::Graphics::IRenderer2D
			{
			protected:
				void Init();
				unsigned int PackColor(const Math::Vector4<float> &color) const;
				void SplitDrawCall();

				GLuint mVAO;
				GLIndexBuffer *mIBO;
				GLsizei mIndexCount = 0;
				unsigned int mVBO;
				Lavio::Graphics::VertexData *mBuffer;
				Lavio::Graphics::VertexData *mBufferStart;

				std::vector<unsigned int> mTextureSlots;
			public:
				GL_API GLBatchRenderer2D();
				GL_API ~GLBatchRenderer2D();

				GL_API void Begin() override;
				GL_API bool Submit(const Lavio::Graphics::Graphic &graphic) override;
				GL_API void End() override;

				GL_API void Flush() override;

			private:
				GL_API GLBatchRenderer2D(const GLBatchRenderer2D& other) = delete;
				GL_API GLBatchRenderer2D operator=(const GLBatchRenderer2D& other) = delete;
			};
		}
	}
}
