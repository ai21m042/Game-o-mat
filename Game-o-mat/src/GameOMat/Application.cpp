#include "Application.h"


namespace GameOMat {

	Application::Application() {
		// stub
	}

	Application::~Application() {
		// stub
	}
	
	void Application::Run() {
		// for testing the event system
		WindowResizeEvent e(1280, 720);
		GOM_TRACE(e);

		while (true) {
			// todo game loop, atm just an endless loop that does nothing
		}
	}
}