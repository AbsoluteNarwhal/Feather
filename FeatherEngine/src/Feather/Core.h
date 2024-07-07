#pragma once

#ifdef _WIN64
	#ifdef FT_BUILD_DLL
		#define FEATHER_API __declspec(dllexport)
	#else
		#define FEATHER_API __declspec(dllimport)
	#endif
#else
	#error Unsupported Platform!
#endif