#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <limits.h>
#include <cerrno>
#include <cstdlib>

enum CASES {
    CHAR,
    INT,
    FLOAT,
    DOUBLE
};

class Converter {
public:
    Converter();
    Converter(Converter const &other);
    Converter &operator=(Converter const &other);
    ~Converter();

    void Convert(std::string const &arg);
};

#endif