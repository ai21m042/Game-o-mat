#pragma once

#include "gompch.h"
#include "GameOMat/Core.h"

namespace GameOMat {

	enum class EventType {

		// placeholder 
		None = 0,

		// events that will or can be called from the window on specific actions
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,

		// game loop relevant events
		ApplicationTick, ApplicationUpdate, ApplicationRender,

		// keyboard input events
		KeyPressed, KeyReleased,

		// mouse input events
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,

	};

	enum EventCategory {

		None = 0,

		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4),

	};

// helper for implementing overrides to sub-events
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

// helper for implementing overrides to sub-events
#define EVENT_CLASS_CATEGORY(category) virtual int GetGategoryFlags() const override { return category; }

	// the event class that holds the necessary fields and methods of an event (to handle)
	class GOM_API Event {
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetGategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); };

		inline bool IsInCategory(EventCategory category) {
			return GetGategoryFlags() & category;
		}
	protected:
		bool mHandled = false;
	};

	// the dispatcher of the event, holds the callback of the event to further handle it in the future
	class EventDispatcher {
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event) : mEvent(event) {
		}
		
		template<typename T>
		bool Dispatch(EventFn<T> func) {
			// check the correct type and call the callback
			if (mEvent.GetEventType() == T::GetStaticType()) {
				mEvent.mHandled = func(*(T*)&mEvent);
				return true;
			}

			return false;
		}

	private:
		Event& mEvent;
	};

	// helper for printing the event-name to the console
	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.ToString();
	}
};