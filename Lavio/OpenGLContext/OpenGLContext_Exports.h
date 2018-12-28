// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#ifdef OPENGLCONTEXT_EXPORTS
#define GL_API __declspec(dllexport) 
#else
#define GL_API __declspec(dllimport) 
#endif