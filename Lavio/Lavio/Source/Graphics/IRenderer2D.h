// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

namespace Lavio
{
	namespace Graphics
	{
		class Graphic;
		namespace GUI {
			class Label;
		}

		class IRenderer2D
		{
		public:
			IRenderer2D(){}
			virtual ~IRenderer2D()
			{
			}

			virtual void Begin() = 0;
			virtual bool Submit(const Graphic &graphic) = 0;
			virtual void Flush() = 0;
			virtual void End() = 0;

		public:
			IRenderer2D(const IRenderer2D &other) = delete;
			IRenderer2D& operator=(const IRenderer2D& rhs) = delete;
		};
	}
}
