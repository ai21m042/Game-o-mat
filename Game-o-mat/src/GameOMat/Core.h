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

// custom bit 'type' (at least for events, later maybe more)
#define BIT(x) (1 << x)

// asserts are mainly for testing / debugging. here we check if something (=x) is true. this has to be enabled by defining the GOM_ENABLE_ASSERTS define
#ifdef GOM_ENABLE_ASSERTS
	#define GOM_ASSERT(x, ...) { if(!(x)) { GOM_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define GOM_CORE_ASSERT(x, ...) { if(!(x)) { GOM_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define GOM_ASSERT(x, ...)
	#define GOM_CORE_ASSERT(x, ...)
#endif