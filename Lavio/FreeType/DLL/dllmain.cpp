// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

// dllmain.cpp : Defines the entry point for the DLL application.
#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
