#include "Converter.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Invalid number of args." << std::endl;
        return 1;
    }

    Converter converter;

    std::string str = argv[1];

    converter.Convert(str);

    return 0;
}