// Student's name: Diego B Soares
// ID number: 145820239
// 29/09/2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Workshop 1
#pragma once
#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H

#include "settings.h"
#include <iomanip>
#include <chrono>
#include <iostream>

namespace seneca {

	class Event {
		const char* m_name;
		std::chrono::nanoseconds m_duration; // total duration in nanoseconds
	public:
		const char* name() const; // return event name
		Event(); // default constructor
		Event(const char* name, const std::chrono::nanoseconds& duration); // parametized constructor
		friend std::ostream& operator<<(std::ostream&, const Event&); // overload operator << so we can print an event object
	};
}
#endif // !SENECA_EVENT_H
