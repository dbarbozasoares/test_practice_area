// Student's name: Diego B Soares
// ID number: 145820239
// 29/09/2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Workshop 1
#pragma once
#ifndef SENECA_LOGGER_H
#define SENECA_LOGGER_H

#include "event.h"
#include <iostream>

namespace seneca {

	class Logger {
		Event* m_events_list{ nullptr };
		int m_event_counter{ 0 };
	public:
		int getCounter() const; // return event counter
		Event& getEvent(int index) const; // return event by index from parameter
		Logger(); // default constructor
		Logger& operator=(Logger&& obj); // move assignment operator
		Logger(Logger&& obj); // move constructor

		// disable copy operators
		Logger(const Logger& obj) = delete;
		Logger& operator=(const Logger& obj) = delete;

		void addEvent(const Event& event); // dynamically add new event into events list 
		~Logger(); // destructor

		// overload operator << to print an object type Logger
		friend std::ostream& operator<<(std::ostream&, const Logger&);
	};
}

#endif // !SENECA_LOGGER_H



