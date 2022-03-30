#include "gompch.h"
#include "Application.h"

#include "GLFW/glfw3.h"

namespace GameOMat {

	// short custom 'macro' for binding the fkt from the application
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	// creating the window (platform independent; Create has to be implement for each platform)
	Application::Application() {
		mWindow = std::unique_ptr<Window>(Window::Create());
		// mWindow->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
		mWindow->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application() {
		// stub
	}

	// we stop the game loop on window close
	bool Application::OnWindowClose(WindowCloseEvent& e) {
		mRunning = false;
		return true;
	}
	
	// the game-loop where we draw a simple colored background
	void Application::Run() {

		// game loop
		while (mRunning) {
			glClearColor(0.3, 0.3, 0.3, 1); // simple grey background :)
			glClear(GL_COLOR_BUFFER_BIT);
			mWindow->OnUpdate();
		}
	}

	// we define the callbacks for the event types
	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);

		// will only be called for window close events -> OnWindowClose, which stops the game-loop
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		GOM_CORE_TRACE("{0}", e);
	}
}