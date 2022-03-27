#pragma once

#include "Event.h"

#include <sstream>

namespace GameOMat {

	// event for moving the mouse in our window
	class GOM_API MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(float x, float y) : mX(x), mY(y) {}

		inline float GetX() const { return mX; }

		inline float GetY() const { return mY; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << mX << ", " << mY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float mX, mY;
	};

	// event for scrolling with our mouse in our window
	class GOM_API MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(float xOffset, float yOffset) : mXOffset(xOffset), mYOffset(yOffset) {}

		inline float GetXOffset() const { return mXOffset; }
		
		inline float GetYOffset() const { return mYOffset; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
			
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float mXOffset, mYOffset;
	};

	// event for clicking a mouse button
	class GOM_API MouseButtonEvent : public Event {
	public:
		inline int GetMouseButton() const { return mButton; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int button) : mButton(button) {}

		int mButton;
	};

	// event for holding a mousebutton click
	class GOM_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << mButton;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	// event for letting go of a mouse click
	class GOM_API MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << mButton;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

}