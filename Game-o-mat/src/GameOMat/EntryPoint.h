#pragma once

#ifdef GOM_PLATFORM_WINDOWS

extern GameOMat::Application* GameOMat::CreateApplication();

int main(int argc, char** argv) {
	printf("Game-O-Mat Engine");

	auto app = GameOMat::CreateApplication();

	app->Run();

	delete app;
}

#endif // GOM
