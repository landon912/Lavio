// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "../RenderAPI.h"
#include "../../Graphics/Buffers/IBuffer.h"
#include "../../Graphics/Buffers/IIndexBuffer.h"
#include "../../Graphics/Buffers/IVertexArray.h"

namespace Lavio
{
	namespace API
	{
		using namespace Graphics;

		class BufferFactory
		{
		public:
			static IBuffer* CreateBuffer(RenderAPI api, float *data, int count, unsigned int componentCount);
			static IIndexBuffer* CreateIndexBuffer(RenderAPI api, unsigned short *data, int count);
			static IVertexArray* CreateVertexArray(RenderAPI api);

		public:
			BufferFactory() = delete;
			BufferFactory(const BufferFactory& other) = delete;
			BufferFactory& operator=(const BufferFactory& rhs) = delete;
			~BufferFactory() = delete;
		};
	}
}