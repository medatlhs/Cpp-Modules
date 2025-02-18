#include "../includes/contact.hpp"
#include "../includes/phonebook.hpp"

void    Contact::displayOnTable(int index) {
    std::cout << "|";
    printSpaces(9);
    std::cout << index; std::cout << "|";
    printSpaces(10 - firstName.length());
    std::cout << (firstName.length() > 10 ? firstName.substr(0, 9) + "." : firstName);
    std::cout << "|";
    printSpaces(10 - lastName.length());
    std::cout << (lastName.length() > 10 ? lastName.substr(0, 9) + "." : lastName);
    std::cout << "|";
    printSpaces(10 - nickName.length());
    std::cout << (nickName.length() > 10 ? lastName.substr(0, 9) + "." : nickName);
    std::cout << "|" << std::endl;
}

void    Contact::displayFullContact() {
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickName << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

std::string getInput(std::string prompt, int flag)
{
    std::string input;

    while (true)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, input)){
            std::cout << std::endl; exit(0);
        }
        if (!isPrintAble(input))
            continue;
        if (input.empty() && (flag || flag == 2)){
            std::cout << "Can't be empty!\n"; continue;
        }
        if (flag == 2)
        {
            if (!ft_isdigit(input)){
                std::cout << "Invlaid phone number!\n"; continue;
            }
        }
        break ;
    }
    return (input);
}

void    Contact::insertContact() {

    firstName = getInput("Enter first name: ", 1);
    lastName = getInput("Enter last name: ", 0);
    nickName = getInput("Enter nick name: ", 0);
    phoneNumber = getInput("Enter phone number: ", 2);
    darkestSecret = getInput("Enter darkest secret: ", 0);
}
