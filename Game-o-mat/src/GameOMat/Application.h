#pragma once

#include "Core.h"

namespace GameOMat {

	class GOM_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}