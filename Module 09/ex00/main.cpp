
#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Error: Expecting one file." << std::endl;
        return 1;
    }
    
    BitcoinExchange btc;
    btc.loadData("./data.csv");
    btc.processInputFile(av[1]);

    return 0;
}
