// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

namespace Lavio
{
	namespace Graphics
	{
		class IBuffer
		{
		public:
			IBuffer()
			{
			}

			virtual ~IBuffer()
			{
			}

			virtual void Bind() const = 0;
			virtual void Unbind() const = 0;

			virtual unsigned int GetComponentCount() const = 0;
		
		public:
			IBuffer(const IBuffer& other) = delete;
			IBuffer& operator=(const IBuffer& other) = delete;
		};
	}
}
