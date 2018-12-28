// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#include "TileLayer.h"
#include "../Source/Platform/Factories/RendererFactory.h"
#include "../Source/World.h"
#include "../../Math/Rect.h"

namespace Lavio
{
	namespace Graphics
	{
		TileLayer::TileLayer(IShader *shader)
			: Layer(API::RendererFactory::Create2DRenderer(World::GetInstance().APIManager->GetCurrentAPI(), true), shader, Matrix4x4<float>::Orthographic(Rect<float>(-16.0f, 16.0f, -9.0f, 9.0f), -1.0f, 1.0f))
		{
		}

		TileLayer::~TileLayer()
		{
		}
	}
}
