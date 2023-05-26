#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cout << "./btc needs an input file." << std::endl;
        return 1;
    }

    std::ifstream input(argv[1]);

    if (!input) {
        std::cout << "Failed to open file." << std::endl;
        return 2;
    }

    BitcoinExchange btc;

    btc.calculateValue(input);

    input.close();
    return 0;
}