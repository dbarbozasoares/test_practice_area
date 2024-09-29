// Student's name: Diego B Soares
// ID number: 145820239
// 29/09/2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Workshop 1
#include "event.h"


namespace seneca {

    // default constructor
    Event::Event() : m_name(nullptr), m_duration(0)
	{
	}

    // parametized constructor
	Event::Event(const char* name, const std::chrono::nanoseconds& duration) : m_name(name), m_duration(duration)
	{
	}

    // return event name
    const char* Event::name() const
    {
        return m_name;
    }

    // overload operator << so we can print an event object
	std::ostream& operator<<(std::ostream& out, const Event& event)
	{
		static int counter = 1;
		
		out << std::right << std::setw(2) << counter++ << ": "
			<< std::right << std::setw(40) << event.m_name << " -> ";
        if (g_settings.m_time_units == "nanoseconds") {
            out << std::right << std::setw(11) << std::chrono::duration_cast<std::chrono::nanoseconds>(event.m_duration).count() << " nanoseconds";
        }
        else if (g_settings.m_time_units == "microseconds") {
            out << std::right << std::setw(8) << std::chrono::duration_cast<std::chrono::microseconds>(event.m_duration).count() << " microseconds";
        }
        else if (g_settings.m_time_units == "milliseconds") {
            out << std::right << std::setw(5) << std::chrono::duration_cast<std::chrono::milliseconds>(event.m_duration).count() << " milliseconds";
        }
        else if (g_settings.m_time_units == "seconds") {
            out << std::right << std::setw(2) << std::chrono::duration_cast<std::chrono::seconds>(event.m_duration).count() << " seconds";
        }

		return out;
	}

}