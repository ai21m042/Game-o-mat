#pragma once

#include "Event.h"

namespace GameOMat {
	
	class GOM_API KeyEvent : public Event {
	public:
		inline int GetKeyCode() const { return mKeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		// we hide the constructor because we define the specific 'unique' events by ourselfs
		KeyEvent(int keycode) : mKeyCode(keycode) {}
		int mKeyCode;
	};

	class GOM_API KeyPressedEvent: public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount): KeyEvent(keycode), mRepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return mRepeatCount; };

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << mKeyCode << " (" << mRepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed);
	private:
		int mRepeatCount;
	};

	class GOM_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << mKeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}