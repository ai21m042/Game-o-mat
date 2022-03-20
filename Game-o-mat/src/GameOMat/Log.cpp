#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace GameOMat {

	std::shared_ptr<spdlog::logger> Log::coreLogger;
	std::shared_ptr<spdlog::logger> Log::clientLogger;

	void Log::Init() {
		// we set the pattern for the log lines in the output (like console)
		spdlog::set_pattern("%^[%T] %n: %v%$"); 

		coreLogger = spdlog::stdout_color_mt("Game-O-Mat");
		coreLogger->set_level(spdlog::level::trace);

		clientLogger = spdlog::stdout_color_mt("Application");
		clientLogger->set_level(spdlog::level::trace);
	}

}