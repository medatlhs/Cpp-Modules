#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;

    public:
        void insertContact();
        void displayFullContact();
        void displayOnTable(int index);
};

void    printSpaces(int n);
bool    isPrintAble(std::string input);

#endif
