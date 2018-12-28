// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "../IRenderer2D.h"
#include "../Source/Graphics/IShader.h"
#include "../Source/Graphics/Graphic.h"

#include <vector>

namespace Lavio
{
	namespace Graphics
	{
		using namespace Math;

		class Layer
		{
		private:
			unsigned short mRenderableSize = 0;
			bool mTooLarge = false;
			//Layer(const Layer &other);
		protected:
			IRenderer2D *mRenderer;
			std::vector<Graphic*> mRenderables;
			IShader *mShader;
			Matrix4x4<float> mProjectionMatrix;
		protected:
			Layer(IRenderer2D *renderer, IShader *shader, Matrix4x4<float> projecitonMatrix);
		public:
			virtual ~Layer();
			virtual void Add(Graphic *renderable);
			virtual void Render();
			virtual void ClearRenderables();

			const std::vector<Graphic*>& GetRenderables() const
			{
				return mRenderables;
			}

		public:
			Layer(const Layer& other) = delete;
			Layer& operator=(const Layer& other) = delete;
		};
	}
}
