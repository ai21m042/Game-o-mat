#include "gompch.h"
#include "Application.h"

#include "GLFW/glfw3.h"

namespace GameOMat {

	Application::Application() {
		mWindow = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() {
		// stub
	}
	
	void Application::Run() {
		// for testing the event system
		WindowResizeEvent e(1280, 720);
		GOM_TRACE(e);

		if (e.IsInCategory(EventCategoryApplication)) {
			while (mRunning) {
				GOM_TRACE(e);
				glClearColor(0.3, 0.3, 0.3, 1); // simple grey background :)
				glClear(GL_COLOR_BUFFER_BIT);
				mWindow->OnUpdate();
			}
		}

		if (e.IsInCategory(EventCategoryInput)) {
			GOM_TRACE(e);
		}
		


		// todo game loop, atm just an endless loop that does nothing
		while (true);
	}
}