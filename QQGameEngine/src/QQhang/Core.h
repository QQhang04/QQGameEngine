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