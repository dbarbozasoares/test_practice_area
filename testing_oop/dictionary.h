// Student's name: Diego B Soares
// ID number: 145820239
// 29/09/2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Workshop 1
#pragma once
#ifndef SENECA_DICTIONARY_H
#define SENECA_DICTIONARY_H

#include "settings.h"
#include <string>
namespace seneca
{
	enum class PartOfSpeech
	{
		Unknown,
		Noun,
		Pronoun,
		Adjective,
		Adverb,
		Verb,
		Preposition,
		Conjunction,
		Interjection,
	};

	struct Word
	{
		std::string m_word{};
		std::string m_definition{};
		PartOfSpeech m_pos = PartOfSpeech::Unknown;
	};

	class Dictionary {
		Word* m_words_array{nullptr};
		int m_dic_size{ 0 };
	public:
		Dictionary() {}; // default constructor
		Dictionary(const char* filename); // initialize a dictionary with words, definition and part of speech
		Dictionary(const Dictionary& dict); // copy constructor
		Dictionary(Dictionary&& other); // move constructor
		Dictionary& operator=(const Dictionary& dict); // copy assignment constructor
		Dictionary& operator=(Dictionary&& other); // move assignment operator
		~Dictionary(); // destructor
		void printPartOfSpeech(const Word& word) const; // get part of speech from a word and prints it
		void searchWord(const char* word); // search word from parameter in dictionary array
		void setPartOfSpeech(const std::string word, PartOfSpeech& pos); // helper member function to set a speech to a word

	};
}

#endif // !SENECA_DICTIONARY_H
