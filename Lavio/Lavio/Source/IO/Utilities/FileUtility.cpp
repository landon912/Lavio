// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "FileUtility.h"

#define WINDOWS 1

#if WINDOWS
#include <Windows.h>
#endif

namespace Lavio
{
	namespace IO
	{
		std::string FileUtility::ReadFile(const char *filepath)
		{
			FILE *file;
			if ((file = fopen(filepath, /*Read&&Text*/"rt")) == nullptr)
			{
#if WINDOWS
				MessageBox(nullptr, TEXT("Invalid Shader File Path"), TEXT("Test"), MB_OK);
#endif
			}
			fseek(file, 0, SEEK_END);
			unsigned long length = ftell(file);
			char *data = new char[length + 1];
			memset(data, 0, length + 1);
			fseek(file, 0, SEEK_SET);
			fread(data, 1, length, file);
			fclose(file);

			std::string result(data);
			delete[] data;
			return result;
		}
	}
}
