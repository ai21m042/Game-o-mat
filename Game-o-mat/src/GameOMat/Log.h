#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace GameOMat {

	// our logging wrapper for centralizing logging (we use spd logger, but anything else is fine)
	class GOM_API Log
	{
	public:
		// here we will init our logger, which will be mainly static available so we can use it anywhere in the engine & therefore implementation/game
		static void Init();

		// we will use this mainly for engine stuff
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return coreLogger; }
		// we will make this available for the client :)
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	};

}

// short cuts for our core logging , which also allows us to disable logging for distriution version
#define GOM_CORE_ERROR(...)		::GameOMat::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GOM_CORE_WARN(...)		::GameOMat::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GOM_CORE_INFO(...)		::GameOMat::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GOM_CORE_TRACE(...)		::GameOMat::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GOM_CORE_FATAL(...)		::GameOMat::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// short cuits for our client logging
#define GOM_ERROR(...)			::GameOMat::Log::GetClientLogger()->error(__VA_ARGS__)
#define GOM_WARN(...)			::GameOMat::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GOM_INFO(...)			::GameOMat::Log::GetClientLogger()->info(__VA_ARGS__)
#define GOM_TRACE(...)			::GameOMat::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GOM_FATAL(...)			::GameOMat::Log::GetClientLogger()->fatal(__VA_ARGS__)

// #define GOM_CORE_ERROR