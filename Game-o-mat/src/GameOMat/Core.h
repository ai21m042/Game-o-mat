#pragma once

#ifdef GOM_PLATFORM_WINDOWS
	#ifdef GOM_BUILD_DLL
		#define GOM_API __declspec(dllexport)
	#else
		#define GOM_API __declspec(dllimport)
	#endif // GOM_BUILD_DLL
#else
	#error Game-O-Mat only supoorts Windows!
#endif // GOM_PLATFORM_WINDOWS
