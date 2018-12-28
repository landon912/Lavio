// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "../RenderAPI.h"
#include "../../IO/Input/IInput.h"

namespace Lavio
{
	namespace API
	{
		class InputFactory
		{
		public:
			static IO::IInput* CreateInput(RenderAPI api);

		public:
			InputFactory() = delete;
			InputFactory(const InputFactory& other) = delete;
			InputFactory& operator=(const InputFactory& rhs) = delete;
			~InputFactory() = delete;
		};
	}
}
