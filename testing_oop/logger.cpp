// Student's name: Diego B Soares
// ID number: 145820239
// 29/09/2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Workshop 1
#include "logger.h"

namespace seneca {

	// return total events
	int Logger::getCounter() const
	{
		return m_event_counter;
	}

	// return an event based on parameter index
	Event& Logger::getEvent(int index) const
	{
		return m_events_list[index];
	}

	// default constructor
	Logger::Logger() : m_events_list(nullptr), m_event_counter(0)
	{
	}

	// move assignment operator
	Logger& Logger::operator=(Logger&& obj)
	{
		if (this != &obj) // check self assignment
		{
			delete[] m_events_list; // delete current resources from this object
			m_events_list = obj.m_events_list;
			m_event_counter = obj.m_event_counter;
			obj.m_events_list = nullptr; // set other object resources to a safe state
		}
		return *this;
	}

	// move constructor
	Logger::Logger(Logger&& obj)
	{
		m_events_list = obj.m_events_list; // copy resources from other object
		m_event_counter = obj.m_event_counter;
		obj.m_events_list = nullptr; // set other object o a safe state
		obj.m_event_counter = 0;
	}
	
	// dynamically add new event into events list 
	void Logger::addEvent(const Event& new_event)
	{
		Event* tmp_array = new Event[m_event_counter + 1]{};

		for (auto i = 0; i < m_event_counter; i++) // copy each event to new array
			tmp_array[i] = m_events_list[i];

		tmp_array[m_event_counter] = new_event; // place new event to last position

		delete[] m_events_list; // deallocate resources from previous events list

		m_events_list = tmp_array; // point to new array with right size

		m_event_counter++;
	}

	// destructor
	Logger::~Logger()
	{
		delete[] this->m_events_list;
		this->m_events_list = nullptr; // set other object o a safe state
	}

	// overload operator << to print an object type Logger
	std::ostream& operator<<(std::ostream& ostr, const Logger& logger)
	{
		for (auto i = 0; i < logger.m_event_counter; i++)
		{
			ostr << logger.m_events_list[i] << std::endl;
		}
		
		return ostr;

	}
}
