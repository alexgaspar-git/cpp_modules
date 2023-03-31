#include "Harl.hpp"

int main(int argc, char **argv) {

    Harl Steve;

    if (argc != 2) {
        std::cout << "Argument required" << std::endl;
        return 1;
    }
    Steve.complainFilter(argv[1]);
    return 0;
}