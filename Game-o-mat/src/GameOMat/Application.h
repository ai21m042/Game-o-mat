#pragma once

#include "Core.h"

#include "GameOMat/Log.h"
#include "GameOMat/Events/ApplicationEvent.h"
#include "Window.h"

namespace GameOMat {

	// our main class for init and running the application
	// the game will have to implement an actual implementation of this class
	class GOM_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		std::unique_ptr<Window> mWindow;
		bool mRunning = true;
	};

	// this is the method where the game inits his class of the application
	Application* CreateApplication();
}