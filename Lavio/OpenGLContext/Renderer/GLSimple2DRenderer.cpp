//// **************************************** Lavio Engine ****************************************
//// **************************** Copyright (c) 2017 All Rights Reserved **************************
//// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************
//
//#include "GLSimple2DRenderer.h"
//#include "../Source/Objects/GameObject.cpp"
//#include "../Source/Graphics/Sprite.h"
//#include "../OpenGL.h"
//
//namespace Lavio
//{
//	namespace OpenGL
//	{
//		namespace Graphics
//		{
//			GLSimple2DRenderer::GLSimple2DRenderer()
//			{
//			}
//
//			GLSimple2DRenderer::~GLSimple2DRenderer()
//			{
//			}
//
//			bool GLSimple2DRenderer::Submit(const Lavio::Graphics::Sprite *graphic)
//			{
//				mRenderQueue.push_back(graphic);
//				return true;
//			}
//
//			void GLSimple2DRenderer::Flush()
//			{
//				/*while (!mRenderQueue.empty())
//				{
//					const Lavio::Graphics::Sprite *sprite = mRenderQueue.front();
//
//					sprite->graphic->GetVAO()->Bind();
//					sprite->graphic->GetIBO()->Bind();
//
//					sprite->graphic->GetShader().SetUniform("ml_matrix", sprite->gameObject->GetTransform().GetTransformationMatrix());
//					glDrawElements(GL_TRIANGLES, sprite->graphic->GetIBO()->GetCount(), GL_UNSIGNED_SHORT, nullptr);
//
//					sprite->graphic->GetIBO()->Unbind();
//					sprite->graphic->GetVAO()->Unbind();
//
//					mRenderQueue.pop_front();
//				}*/
//			}
//		}
//	}
//}
