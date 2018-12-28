// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#ifdef FREETYPEDLL_EXPORTS  
#define FREETYPE_API __declspec(dllexport)   
#else  
#define FREETYPE_API __declspec(dllimport)   
#endif  