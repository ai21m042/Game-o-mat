#pragma once

#ifdef GOM_PLATFORM_WINDOWS

// this method has to be implemented by the game
extern GameOMat::Application* GameOMat::CreateApplication();

int main(int argc, char** argv) {
	printf("Starting Game-O-Mat Engine ...\n");

	auto app = GameOMat::CreateApplication();

	app->Run();

	delete app;
}

#endif // GOM_PLATFORM_WINDOWS
