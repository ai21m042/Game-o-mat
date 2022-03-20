#pragma once

#ifdef GOM_PLATFORM_WINDOWS

// this method has to be implemented by the game
extern GameOMat::Application* GameOMat::CreateApplication();

int main(int argc, char** argv) {
	GameOMat::Log::Init();
	GOM_CORE_INFO("Starting Game-O-Mat ...");

	GOM_CORE_WARN("Checking Core Logger");
	GOM_WARN("Checking Client Logger");

	auto app = GameOMat::CreateApplication();
	app->Run();
	delete app;
}

#endif // GOM_PLATFORM_WINDOWS
