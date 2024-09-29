// Student's name: Diego B Soares
// ID number: 145820239
// 29/09/2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Workshop 1
#include "timeMonitor.h"

namespace seneca {
	void TimeMonitor::startEvent(const char* name)
	{
		m_tmonitor_event_name = name;
		m_start_time = std::chrono::high_resolution_clock::now();
	}

	Event TimeMonitor::stopEvent()
	{
		m_end_time = std::chrono::high_resolution_clock::now();
		auto total_time = std::chrono::duration_cast<std::chrono::nanoseconds>(m_end_time - m_start_time);

		Event event_updated(m_tmonitor_event_name, total_time);

		return event_updated;

	}
}
