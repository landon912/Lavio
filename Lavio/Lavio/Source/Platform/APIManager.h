// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "RenderAPI.h"

namespace Lavio
{
	namespace API
	{
		class APIManager
		{
		private:
			RenderAPI currentAPI;
		public:
			explicit APIManager(RenderAPI currentApi) : currentAPI(currentApi)
			{
			}

			void SetCurrentAPI(RenderAPI api)
			{
				currentAPI = api;
			}

			RenderAPI GetCurrentAPI() const
			{
				return currentAPI;
			}

		public:
			APIManager(const APIManager& other) = delete;
			APIManager& operator=(const APIManager& other) = delete;
		};
	}
}