#pragma once

// here we specify mainly the external api endpoints in our ddl, that will be available to the users of game-o-mat

// currently we only support windows as platform
#ifdef GOM_PLATFORM_WINDOWS
	#ifdef GOM_BUILD_DLL
		#define GOM_API __declspec(dllexport)
	#else
		#define GOM_API __declspec(dllimport)
	#endif // GOM_BUILD_DLL
#else
	#error Game-O-Mat only supoorts Windows!
#endif // GOM_PLATFORM_WINDOWS

#define BIT(x) (1 << x)