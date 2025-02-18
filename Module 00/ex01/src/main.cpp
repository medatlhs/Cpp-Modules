#include "../includes/phonebook.hpp"
#include <iostream>

int main() {
    PhoneBook   myPhoneBook;
    std::string command;

    while(true)
    {
        std::cout << "Enter a command: ";
        if (!std::getline(std::cin, command))
            return (std::cout << std::endl, 0);
        if (command == "ADD")
            myPhoneBook.addContact();
        else if (command == "SEARCH")
            myPhoneBook.searchContact();
        else if (command == "EXIT")
            return 0;
    }
    return 0;
}
