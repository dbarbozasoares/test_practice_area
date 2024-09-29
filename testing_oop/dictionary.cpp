// Student's name: Diego B Soares
// ID number: 145820239
// 29/09/2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Workshop 1
#include "dictionary.h"
#include <iostream>
#include <fstream>
#include <cstring>

namespace seneca
{
    Dictionary::Dictionary(const char* filename)
    {
        if (filename != nullptr) { // make sure filename is not pointing to a nullptr
            std::ifstream file(filename);
            std::string word;
            int total_words = 0; // size for dictionary


            if (file.is_open())
            {
                while (getline(file, word))
                {
                    total_words++;
                }

                file.clear(); // Clear any EOF flag
                file.seekg(0, std::ios::beg); // Move to the beginning of the file

                this->m_dic_size = total_words; // set size of dictionary

                this->m_words_array = new Word[total_words + 1]; // dynamically create an array for words

                for (int i = 0; i < this->m_dic_size; i++) {

                    
                    getline(file, word, ','); // read the word itself
                    m_words_array[i].m_word = word;

                    getline(file, word, ','); // reads the part of speech
                    setPartOfSpeech(word, m_words_array[i].m_pos);

                    getline(file, word); // reads word's definition
                    m_words_array[i].m_definition = word;
                }
            }
            else {
                this->m_words_array = nullptr;
                this->m_dic_size = 0;
            }
        }
    }

    // copy constructor
    Dictionary::Dictionary(const Dictionary& dict)
    {
        m_dic_size = dict.m_dic_size;
        m_words_array = new Word[m_dic_size]; // set new size for array
        for (auto i = 0; i < dict.m_dic_size; i++)
        {
            m_words_array[i] = dict.m_words_array[i]; // deep copy each element
        }

    }

    // move constructor
    Dictionary::Dictionary(Dictionary&& other)  {
        m_dic_size = other.m_dic_size; // Copy size
        m_words_array = other.m_words_array; // Shallow copy from other object

        other.m_dic_size = 0;
        other.m_words_array = nullptr;
    }

    // copy assignment operator
    Dictionary& Dictionary::operator=(const Dictionary& dict) {
        if (this != &dict) { // Self-assignment check
            // Free existing resources
            delete[] m_words_array; // delete current resources

            // Perform deep copy
            m_dic_size = dict.m_dic_size;
            if (m_dic_size > 0) {
                m_words_array = new Word[m_dic_size]; // Allocate new memory size
                for (int i = 0; i < m_dic_size; ++i) {
                    m_words_array[i] = dict.m_words_array[i]; // Deep copy each element
                }
            }
            else {
                m_words_array = nullptr;
            }
        }
        return *this;
    }

    // move assignment operator
    Dictionary& Dictionary::operator=(Dictionary&& other) {

        if (this != &other) { // Self-assignment check
            
            delete[] m_words_array; // Delete currente resources

            // Shallow copy resources
            m_dic_size = other.m_dic_size;
            m_words_array = other.m_words_array;

            other.m_dic_size = 0;
            other.m_words_array = nullptr; // set to a safe state
        }
        return *this;
    }

    // go trough dictionary and locates word, if it doesnt contain this word, print word not found
    void Dictionary::searchWord(const char* word)
    {
        bool is_already_printed = false;
        int word_counter = 0;
        if (word != nullptr && m_words_array != nullptr) {
            for (int i = 0; i < m_dic_size; i++) {
                if (strcmp(m_words_array[i].m_word.c_str(), word) == 0) {
                    if (!is_already_printed) {
                        std::cout << word;
                        is_already_printed = true; // set first word found and printed
                    }
                    if (word_counter != 0) { // if first word is already printed, prints only spaces with word length
                        for (size_t i = 0; i < strlen(word); i++) {
                            std::cout << " ";
                        }
                    }
                    std::cout << " - ";
                    if (g_settings.m_verbose == true) {
                        printPartOfSpeech(m_words_array[i]); // display part of speech using helper function
                    }

                    std::cout << m_words_array[i].m_definition << std::endl;
                    word_counter++; // increase words found
                    if (g_settings.m_show_all == false) {
                        i = m_dic_size;
                    }
                }
            }
        }
        // check for nullptr and if word is not in dictionary
        if (word == nullptr || m_words_array == nullptr || is_already_printed == false) {
            std::cout << "Word '" << word << "' was not found in the dictionary." << std::endl;
        }
    }

    void Dictionary::setPartOfSpeech(const std::string word, PartOfSpeech &pos) {
        if (word == "n." || word == "n. pl.") {
            pos = PartOfSpeech::Noun;
        }
        else if (word == "adv.") {
            pos = PartOfSpeech::Adverb;
        }
        else if (word == "a.") {
            pos = PartOfSpeech::Adjective;
        }
        else if (word == "v." || word == "v. i." || word == "v. t." || word == "v. t. & i.") {
            pos = PartOfSpeech::Verb;
        }
        else if (word == "prep.") {
            pos = PartOfSpeech::Preposition;
        }
        else if (word == "pron.") {
            pos = PartOfSpeech::Pronoun;
        }
        else if (word == "conj.") {
            pos = PartOfSpeech::Conjunction;
        }
        else if (word == "interj.") {
            pos = PartOfSpeech::Interjection;
        }
        else {
            pos = PartOfSpeech::Unknown;
        }
    }

    // helper function to print part of speech basing on word pos
    void Dictionary::printPartOfSpeech(const Word& word)const {
        switch (word.m_pos) {
        case PartOfSpeech::Unknown:
            break;
        case PartOfSpeech::Verb:
            std::cout << "(verb) ";
            break;
        case PartOfSpeech::Adjective:
            std::cout << "(adjective) ";
            break;
        case PartOfSpeech::Conjunction:
            std::cout << "(conjuction) ";
            break;
        case PartOfSpeech::Interjection:
            std::cout << "(interjection) ";
            break;
        case PartOfSpeech::Preposition:
            std::cout << "(preposition) ";
            break;
        case PartOfSpeech::Pronoun:
            std::cout << "(pronoun) ";
            break;
        case PartOfSpeech::Adverb:
            std::cout << "(adverb) ";
            break;
        case PartOfSpeech::Noun:
            std::cout << "(noun) ";
            break;
        default:
            break;
        }
    }

    // destructor
    Dictionary::~Dictionary()
    {
        if (m_words_array != nullptr) {
            delete[] m_words_array;
            m_words_array = nullptr;
        }
    }
}