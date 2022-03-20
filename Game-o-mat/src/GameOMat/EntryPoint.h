#pragma once

#ifdef GOM_PLATFORM_WINDOWS

// this method has to be implemented by the game
extern GameOMat::Application* GameOMat::CreateApplication();

int main(int argc, char** argv) {
	printf("Starting Game-O-Mat Engine ...\n");

	GameOMat::Log::Init();
	//	GOM_CORE_WARN("Initialized Logging!");
	//	int a = 13;
	//	GOM_INFO("Hello Game-O-Mat!, test var = {0}", a);

	auto app = GameOMat::CreateApplication();
	app->Run();
	delete app;
}

#endif // GOM_PLATFORM_WINDOWS
