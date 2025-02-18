#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include "contact.hpp"
#define MAXCONTACTS 8

class PhoneBook {
    private:
        Contact contacts[MAXCONTACTS];
        int     index;
        int     requestedIndex;
        int     totalContacts;

    public:
        PhoneBook() {
            index = 0;
            totalContacts = 0;
        }
        void    addContact();
        void    searchContact();
        void    requestIndex();
};

bool    ft_isdigit(std::string input);
bool    ft_isValid(std::string input);
void    printSpaces(int n);
void    printTable();

#endif
