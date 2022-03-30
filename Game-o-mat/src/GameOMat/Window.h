#pragma once

// our main display-window implementation (platform independent)

#include "gompch.h"

#include "Core.h"
#include "Events/Event.h"

namespace GameOMat {

	// contains the values for the display window independent of the platform
	struct WindowProps {
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Game-O-Mat",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height) {
		}
	};

	// contains the methods for the display window that has to be implemented by each platform (windows, macos and so on) -> everything virtual
	class GOM_API Window {
	public:
		// custom type for readability
		using EventCallbackFn = std::function<void(Event&)>;

		// destructor
		virtual ~Window() {}

		// render fkt that will / should be called regulary (~ fps)
		virtual void OnUpdate() = 0;

		// with of the display window
		virtual unsigned int GetWidth() const = 0;

		// height of the display window
		virtual unsigned int GetHeight() const = 0;

		// set a specific callback for specific event 
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		// creates the current window with specific props
		static Window* Create(const WindowProps& props = WindowProps());
	};
}