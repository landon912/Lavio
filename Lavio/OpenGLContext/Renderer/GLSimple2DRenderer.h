//// **************************************** Lavio Engine ****************************************
//// **************************** Copyright (c) 2017 All Rights Reserved **************************
//// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************
//
//#pragma once
//
//#include "../Source/Graphics/IRenderer2D.h"
//
//#include <deque>
//
//#ifdef OPENGLCONTEXT_EXPORTS
//#define GL_API __declspec(dllexport) 
//#else
//#define GL_API __declspec(dllimport) 
//#endif
//
//namespace Lavio
//{
//	namespace Graphics
//	{
//		class Sprite;
//	}
//}
//
//namespace Lavio
//{
//	namespace OpenGL
//	{
//		namespace Graphics
//		{
//			class GLSimple2DRenderer : public Lavio::Graphics::IRenderer2D
//			{
//			private:
//				std::deque<const Lavio::Graphics::Sprite*> mRenderQueue;
//			public:
//				GL_API GLSimple2DRenderer();
//				GL_API ~GLSimple2DRenderer();
//
//				GL_API void Begin() override
//				{
//				}
//
//				GL_API bool Submit(const Lavio::Graphics::Sprite *sprite) override;
//				GL_API void Flush() override;
//				GL_API void End() override
//				{
//				}
//			};
//		}
//	}
//}
