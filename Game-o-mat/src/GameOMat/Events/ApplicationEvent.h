#pragma once

#include "Event.h"

namespace GameOMat {

	// event for resizing our displayed window to another width and or height
	class GOM_API WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) : mWidth(width), mHeight(height) {}

		inline unsigned int GetWidth() const { return mWidth; }
		inline unsigned int GetHeight() const { return mHeight; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowResizeEvent: " << mWidth << ", " << mHeight;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
			
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		unsigned int mWidth, mHeight;
	};

	// event for closing the main window
	class GOM_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	// intern application event for game loop
	class GOM_API AppTickEvent : public Event {
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(ApplicationTick)

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	// intern application event to start one game-logic interval
	class GOM_API AppUpdateEvent : public Event {
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(ApplicationUpdate)

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	// intern application event to start one frame render
	class GOM_API AppRenderEvent : public Event {
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(ApplicationRender)

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}