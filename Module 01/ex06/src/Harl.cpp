#include "../Includes/Harl.hpp"

Harl::Harl() {
}

Harl::~Harl() {
}

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]\n"
              << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n"
              << "I really do!\n" << std::endl;
}

void Harl::info(void) {
    std::cout << "[ INFO ]\n"
              << "I cannot believe adding extra bacon costs more money.\n"
              << "You didnt putenough bacon in my burger! If you did, I wouldnt be asking for more!\n" << std::endl;
}

void Harl::warning(void) {
    std::cout << "[ WARNING ]\n"
              << "I think I deserve to have some extra bacon for free.\n"
              << "Ive been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error(void) {
    std::cout << "[ ERROR ]\n"
              << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain( std::string level ) {
    void(Harl::*ptr[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[] = {"debug", "info", "warning", "error"};
    for (int i = 0; i < 4; i++) 
    {
        if (level == levels[i]) {
            (this->*ptr[i])();
            return ;
        }
    }
}
