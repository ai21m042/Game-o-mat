#pragma once

#include "Core.h"

namespace GameOMat {

	// our main class for init and running the application
	// the game will have to implement an actual implementation of this class
	class GOM_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// this is the method where the game inits his class of the application
	Application* CreateApplication();
}