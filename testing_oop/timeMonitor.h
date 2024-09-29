// Student's name: Diego B Soares
// ID number: 145820239
// 29/09/2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Workshop 1
#pragma once
#ifndef SENECA_TIMEMONITOR_H
#define SENECA_TIMEMONITOR_H
#include "event.h"

namespace seneca {
	class TimeMonitor {
		std::chrono::high_resolution_clock::time_point m_start_time; // start event time
		std::chrono::high_resolution_clock::time_point m_end_time; // end event time
		const char* m_tmonitor_event_name;
	public:
		void startEvent(const char* name); // start time for new event a set the event name
		Event stopEvent(); // generates total time based on (m_end_time - m_start_time), creates a new event with name and total time and return it
	};
}
#endif // !SENECA_TIMEMONITOR_H
