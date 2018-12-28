// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#include "Graphic.h"

#include "../Platform/Factories/TextureFactory.h"
#include "../World.h"
#include "../Platform/Factories/ShaderFactory.h"

namespace Lavio
{
	namespace Graphics
	{
		Graphic::Graphic(bool isBatched, Vector2<float> size, const Color &color, IShader &shader) : mSize(size), mColor(color), /*mVertexArray(nullptr), mIndexBuffer(nullptr), */mShader(shader)
		{
			SetUVDefaults();
		}

		Graphic::Graphic(bool isBatched, Vector2<float> size, const ITexture &texture, IShader &shader) : mSize(size), mColor(Color(255, 255, 255, 255)), mTexture(&texture),/* mVertexArray(nullptr), mIndexBuffer(nullptr), */mShader(shader)
		{
			SetUVDefaults();
		}

		Graphic::Graphic(const Graphic &other) : mShader(*API::ShaderFactory::CreateShader(World::GetInstance().APIManager->GetCurrentAPI(), other.mShader.GetShaderVertPath(), other.mShader.GetShaderFragPath()))
		{
			mSize = other.mSize;
			mColor = other.mColor;
			mUV = other.mUV;

			if (other.mTexture != nullptr) 
			{
				mTexture = API::TextureFactory::CreateTexture(World::GetInstance().APIManager->GetCurrentAPI(), new ImageData(other.mTexture->GetImageData()));
			}

			/*mVertexArray = API::BufferFactory::CreateVertexArray(World::GetInstance().APIManager->GetCurrentAPI());
			*mVertexArray = *other.mVertexArray;

			mIndexBuffer = API::BufferFactory::CreateIndexBuffer(World::GetInstance().APIManager->GetCurrentAPI(), other.mIndexBuffer->GetReadPointerForBuffer(), other.mIndexBuffer->GetCount());*/
		}

		Graphic& Graphic::operator=(const Graphic& other)
		{
			Graphic copy = other;
			mTexture = other.mTexture;

			std::swap(mColor, copy.mColor);
			std::swap(mSize, copy.mSize);
			std::swap(mUV, copy.mUV);
			return *this;
		}

		Graphic::~Graphic()
		{
			/*if (mVertexArray || mIndexBuffer)
			{
				delete mVertexArray;
				delete mIndexBuffer;
			}*/

			//TODO:Check if texture could be unloaded
			/*Log::DebugLog(mTexture->GetImageData().path);
			if (mTexture != nullptr) 
			{
				delete mTexture;
			}*/
		}

		void Graphic::SetUVDefaults()
		{
			//defualt UV coords
			mUV.push_back(Vector2<float>(0, 0));
			mUV.push_back(Vector2<float>(0, 1));
			mUV.push_back(Vector2<float>(1, 1));
			mUV.push_back(Vector2<float>(1, 0));
		}

		
	}
}
