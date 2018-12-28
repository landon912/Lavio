// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include <fstream>

namespace Lavio
{
	namespace IO
	{
		struct FileUtility
		{
			static std::string ReadFile(const char *filepath);

		private:
			FileUtility() {}
			~FileUtility() {}
			FileUtility(const FileUtility& other);
		};
	}
}
