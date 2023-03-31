#include "Harl.hpp"

int main() {

    Harl Steve;

    Steve.complain("DEBUG");
    std::cout << std::endl;
    Steve.complain("INFO");
    std::cout << std::endl;
    Steve.complain("WARNING");
    std::cout << std::endl;
    Steve.complain("ERROR");
    std::cout << std::endl;

    return 0;
}