#pragma once

#ifdef QQH_PLATFORM_WINDOWS
	#ifdef QQH_BUILD_DLL
		#define QQH_API __declspec(dllexport)
	#else
		#define QQH_API __declspec(dllimport)
	#endif
#else
	#error QQH Engine only supports Windows
#endif

#ifdef QQH_ENABLE_ASSERTS
	#define QQH_ASSERT(x, ...) { if(!(x)) { QQH_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define QQH_CORE_ASSERT(x, ...) { if(!(x)) { QQH_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define QQH_ASSERT(x, ...)
	#define QQH_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)