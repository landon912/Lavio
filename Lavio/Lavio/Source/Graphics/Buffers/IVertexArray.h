// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once
#include <vector>

namespace Lavio
{
	namespace Graphics
	{
		class IVertexArray
		{
		protected:
			std::vector<IBuffer*> mBuffers;
		public:
			IVertexArray()
			{
			}

			virtual ~IVertexArray()
			{
			}

			//virtual void AddBuffer(IBuffer *buffer, unsigned int index, unsigned int stride) = 0;

			//virtual void GetReadPointerForBuffer() const = 0;
			virtual void Bind() const = 0;
			virtual void Unbind() const = 0;

		public:
			IVertexArray(const IVertexArray& other) = delete;
			IVertexArray& operator=(const IVertexArray& other) = delete;
		};
	}
}
