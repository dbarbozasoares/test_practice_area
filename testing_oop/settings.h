// Student's name: Diego B Soares
// ID number: 145820239
// 29/09/2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Workshop 1
#pragma once
#ifndef SENECA_SETTINGS_H
#define SENECA_SETTINGS_H
#include <string>

namespace seneca {

	class Settings {
	public:
		bool m_show_all = false; // if true prints out all definitions if more than one
		bool m_verbose = false; // prints out part of speech of a word if it exists #default 'false'
		std::string m_time_units = "nanoseconds"; // stores the time units to be used when printing duration of various operations #default 'nanoseconds'
	};

	extern Settings g_settings;
}
#endif // !SENECA_SETTINGS_H
