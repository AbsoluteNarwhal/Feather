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

#ifdef FT_ENABLE_ASSERTS
	#define FT_LOG_ASSERT(x, ...) { if(!(x)) { FT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define FT_CORE_ASSERT(x, ...) { if(!(x)) { FT_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define FT_LOG_ASSERT(x, ...)
	#define FT_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)