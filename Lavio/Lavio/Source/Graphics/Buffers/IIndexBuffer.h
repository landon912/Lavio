// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

namespace Lavio
{
	namespace Graphics
	{
		class IIndexBuffer
		{
		public:
			IIndexBuffer()
			{
			}

			virtual ~IIndexBuffer()
			{
			}

			virtual void Bind() const = 0;
			virtual void Unbind() const = 0;

			virtual unsigned int GetCount() const = 0;
			virtual unsigned short* GetReadPointerForBuffer() const = 0;

		public:
			IIndexBuffer(const IIndexBuffer& other) = delete;
			IIndexBuffer& operator=(const IIndexBuffer& other) = delete;
		};
	}
}
