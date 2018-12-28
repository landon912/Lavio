// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "../Graphics/IShader.h"
#include "Textures/ITexture.h"
#include "Color.h"
#include "../Objects/Component.h"

#include <vector>

namespace Lavio
{
	namespace Graphics
	{
		class Graphic : public Component
		{
		private:
			void SetUVDefaults();
		protected:
			Vector2<float> mSize;
			Color mColor;
			std::vector<Vector2<float>> mUV;
			const ITexture *mTexture = nullptr;
		public:
			Graphic(bool isBatched, Vector2<float> size, const Color &color, IShader &shader);
			Graphic(bool isBatched, Vector2<float> size, const ITexture &texture, IShader &shader);
			Graphic(const Graphic& other);
			Graphic& operator=(const Graphic& other);
			virtual ~Graphic();

			//IVertexArray *mVertexArray;
			//IIndexBuffer *mIndexBuffer;
			IShader &mShader;
		public:
			//const IVertexArray* GetVAO() const
			//{
			//	return mVertexArray;
			//}

			//const IIndexBuffer* GetIBO() const
			//{
			//	return mIndexBuffer;
			//}

			void SetColor(const Color& color)
			{
				mColor = color;
			}

			IShader& GetShader() const
			{
				return mShader;
			}

			const Vector2<float>& GetSize() const
			{
				return mSize;
			}

			const Color& GetColor() const
			{
				return mColor;
			}

			const std::vector<Vector2<float>>& GetUV() const
			{
				return mUV;
			}

			unsigned int GetTextureID() const
			{
				return mTexture ? mTexture->GetTextureID() : 0;
			}
		};
	}
}