
#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    if (ac != 2)
        return std::cerr << "Error: Expecting one file." << std::endl, 1;
    
    BitcoinExchange btc;

    try {
        btc.loadData("./data.csv");
        btc.processInputFile(av[1]);
    } catch(const std::exception& e) {
        return std::cerr << e.what() << '\n', 1;
    }

    return 0;
}
