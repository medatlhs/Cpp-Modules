#include "../includes/phonebook.hpp"

bool    ft_isdigit(std::string input) {
    if (input.empty())
        return false;
    int i;
    for (i = 0; i < (int)input.length(); i++)
        if (!isblank(input[i]))
            break ;
    if (!input[i])
        return false;
    int k;
    for (k = i; k < (int)input.length(); k++)
        if (!isdigit(input[k]))
            break ;
    for (i = k; i < (int)input.length(); i++)
        if (!isblank(input[i]))
            return false;
    return true;
}

bool    ft_isValid(std::string input) {
    if (input.empty())
        return (false);
    int i = -1;
    while (input[++i] == ' ' || input[i] == '\t');
    if (!input[i])
        return (false);
    int total = 0;
    int nbrs = 0;
    while (isdigit(input[i]))
    {
        int number = input[i] - '0';
        total = (total*10) + number;
        i++;
        nbrs++;
        if (total > 8 || nbrs > 1)
            return false;
    }
    return (true);
}

bool    isPrintAble(std::string input)
{
    for (int i = 0; i < (int)input.length(); i++)
        if (!std::isprint(input[i])) {
            std::cout << "Invalid Input!" << std::endl;
            return false;
        }
    return true;
}

void printSpaces(int n) {
    if (n <= 0)
        return ;
    for (int i = 0; i < n; i++) {
        std::cout << " ";
    }
}

void    printTable() {
    std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
}
