// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#include "GLBatch2DRenderer.h"
#include "../Source/Objects/GameObject.h"
#include "../Source/Objects/Transform.cpp"
#include "../Source/Graphics/Graphic.h"
#if DEBUG_BUILD
#include "../../Debug/Debugging/Log.h"
#endif

#include "../../FreeType/FreeType-GL/freetype-gl.h"

namespace Lavio
{
	namespace OpenGL
	{
		namespace Graphics
		{
			GLBatchRenderer2D::GLBatchRenderer2D()
			{
				Init();
			}

			GLBatchRenderer2D::~GLBatchRenderer2D()
			{
				delete mIBO;
				glDeleteBuffers(1, &mVBO);
			}

			void GLBatchRenderer2D::Init()
			{
				glGenVertexArrays(1, &mVAO);
				glGenBuffers(1, &mVBO);

				glBindVertexArray(mVAO);
				glBindBuffer(GL_ARRAY_BUFFER, mVBO);

				glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, nullptr, GL_DYNAMIC_DRAW);

				glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
				glEnableVertexAttribArray(SHADER_UV_INDEX);
				glEnableVertexAttribArray(SHADER_TID_INDEX);
				glEnableVertexAttribArray(SHADER_COLOR_INDEX);

				glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, reinterpret_cast<const void*>(offsetof(Lavio::Graphics::VertexData, VertexData::vertex)));
				glVertexAttribPointer(SHADER_UV_INDEX, 2, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, reinterpret_cast<const void*>(offsetof(Lavio::Graphics::VertexData, VertexData::uv)));
				glVertexAttribPointer(SHADER_TID_INDEX, 1, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, reinterpret_cast<const void*>(offsetof(Lavio::Graphics::VertexData, VertexData::textureID)));
				glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_UNSIGNED_BYTE, GL_TRUE, RENDERER_VERTEX_SIZE, reinterpret_cast<const void*>(offsetof(Lavio::Graphics::VertexData, VertexData::color)));

				glBindBuffer(GL_ARRAY_BUFFER, 0);

				GLushort indices[RENDERER_INDICES_SIZE];

				int offset = 0;
				for (unsigned int i = 0; i < RENDERER_INDICES_SIZE; i += 6)
				{
					indices[i] = offset;
					indices[i + 1] = offset + 1;
					indices[i + 2] = offset + 2;

					indices[i + 3] = offset + 2;
					indices[i + 4] = offset + 3;
					indices[i + 5] = offset + 0;

					//amount of vertices
					offset += 4;
				}

				mIBO = new GLIndexBuffer(indices, RENDERER_INDICES_SIZE);

				glBindVertexArray(0);
			}

			void GLBatchRenderer2D::Begin()
			{
				glBindBuffer(GL_ARRAY_BUFFER, mVBO);
				mBuffer = static_cast<Lavio::Graphics::VertexData*>(glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY));
				mBufferStart = mBuffer;
				mIndexCount = 0;
			}

			void GLBatchRenderer2D::SplitDrawCall()
			{
				End();
				Flush();
				Begin();
			}

			bool GLBatchRenderer2D::Submit(const Lavio::Graphics::Graphic &graphic)
			{
#if DEBUG_BUILD
				if (mBuffer - mBufferStart > 4 * RENDERER_MAX_GRAPHICS)
				{
					Log::DebugLog("Render Batch is too large. Maximum of 10,000 graphics in a single batch renderer!");
					return false;
				}
#endif

				const Component* component = dynamic_cast<const Component*>(&graphic);

				const Vector3<float> &position = component->GetParentGameObject().GetTransform().GetPosition(false);
				const Matrix4x4<float> &matrix = component->GetParentGameObject().GetTransform().GetTransformationMatrix();

				const Vector2<float> &size = graphic.GetSize();
				unsigned int color = 0;

				const std::vector<Vector2<float>> &uv = graphic.GetUV();
				const unsigned int textureID = graphic.GetTextureID();

				//opengl doesn't like ints too much
				float textureSlot = 0.0f;

				if (textureID > 0)
				{
					bool found = false;

					//search for texture already assigned to sampler
					for (unsigned int i = 0; i < mTextureSlots.size(); i++)
					{
						if (mTextureSlots[i] == textureID)
						{
							found = true;
							textureSlot = static_cast<float>(i + 1);
							break;
						}
					}

					if (!found)
					{
						if (mTextureSlots.size() >= 32)
						{
							SplitDrawCall();
						}

						mTextureSlots.push_back(textureID);
						textureSlot = static_cast<float>(mTextureSlots.size());
					}
				}
				//else
				{
					color = graphic.GetColor().GetPackedColor();
				}

				mBuffer->vertex = matrix * position;
				mBuffer->uv = uv[0];
				mBuffer->textureID = textureSlot;
				mBuffer->color = color;
				mBuffer++;

				mBuffer->vertex = matrix * Vector3<float>(position.x, position.y + size.y, position.z);
				mBuffer->uv = uv[1];
				mBuffer->textureID = textureSlot;
				mBuffer->color = color;
				mBuffer++;

				mBuffer->vertex = matrix * Vector3<float>(position.x + size.x, position.y + size.y, position.z);
				mBuffer->uv = uv[2];
				mBuffer->textureID = textureSlot;
				mBuffer->color = color;
				mBuffer++;

				mBuffer->vertex = matrix * Vector3<float>(position.x + size.x, position.y, position.z);
				mBuffer->uv = uv[3];
				mBuffer->textureID = textureSlot;
				mBuffer->color = color;
				mBuffer++;

				mIndexCount += 6;

				return true;
			}


			void GLBatchRenderer2D::End()
			{
				glUnmapBuffer(GL_ARRAY_BUFFER);
				glBindBuffer(GL_ARRAY_BUFFER, 0);

				//maybe??
				//mTextureSlots.clear();
			}

			void GLBatchRenderer2D::Flush()
			{
				for (unsigned int i = 0; i < mTextureSlots.size(); i++)
				{
					//this relies on GLTEXTURE_X being in linear values
					glActiveTexture(GL_TEXTURE0 + i);
					glBindTexture(GL_TEXTURE_2D, mTextureSlots[i]);
				}

				glBindVertexArray(mVAO);
				mIBO->Bind();

				glDrawElements(GL_TRIANGLES, mIndexCount, GL_UNSIGNED_SHORT, nullptr);

				mIBO->Unbind();
				glBindVertexArray(0);

				mIndexCount = 0;
			}
		}
	}
}
