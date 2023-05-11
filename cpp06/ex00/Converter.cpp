#include "Converter.hpp"

// ########################################

Converter::Converter() {}

Converter::Converter(Converter const &other) {
    (void)other;
};

Converter &Converter::operator=(Converter const &other) {
    (void)other;
    return *this;
}

Converter::~Converter() {}

// ########################################

static bool is_inf(std::string str) {
    return (str == "-inf" || str == "+inf"
    || str == "-inff" || str == "+inff" 
    || str == "nan" || str == "nanf");
}

static void convert_inf(std::string str) {
    if (str == "-inf" || str == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
    } else if (str == "+inf" || str == "+inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
    } else if (str == "nan" || str == "nanf") {
        std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
    }
}

static void display_converted(char convChar, int convInt, float convFloat, double convDouble) {
    if (isprint(convChar))
        std::cout << "char: " << convChar << std::endl;
    else
        std::cout << "char: non printable char" << std::endl;
    std::cout << "int: " << convInt << std::endl;
    std::cout << "float: " << convFloat << "f" << std::endl;
    std::cout << "double: " << convDouble << std::endl;
}

static int ford(std::string str) {
    int i = 0;
    if (str[0] == '-')
        i++;
    while (isdigit(str[i]))
        i++;
    i++;
    while (isdigit(str[i]))
        i++;
    if (!str[i])
        return DOUBLE;
    if (str[i] == 'f' && !str[i + 1])
        return FLOAT;
    return -1;
}

static int get_scalar(std::string str) {
    if (str.size() == 1 && isalpha(str[0]))
        return (CHAR);
    int i = 0;
    if (str[0] == '-')
        i++;
    if (!str[i])
        return -1;
    while (isdigit(str[i]))
        i++;
    if (!str[i])
        return INT;
    if (str[i] == '.') {
        if (!str[i + 1])
            return -1;
        return ford(str);
    }
    return -1;
}

static void	convert_char( std::string str ) {
	char	convChar = str[0];
	int		convInt = static_cast<int>(convChar);
	float	convFloat = static_cast<float>(convChar);
	double	convDouble = static_cast<double>(convChar);
	display_converted(convChar, convInt, convFloat, convDouble);
}

static void convert_int(std::string str) {
    std::istringstream iss(str);
    long long overflow;
    iss >> overflow;
    if (overflow > INT_MAX || overflow < INT_MIN) {
        std::cout << "int overflow" << std::endl;
        return ;
    }
    int convInt = overflow;
    char    convChar = static_cast<char>(convInt);
	float	convFloat = static_cast<float>(convInt);
	double	convDouble = static_cast<double>(convInt);
	display_converted(convChar, convInt, convFloat, convDouble);
}

static void convert_float(std::string str) {
    errno = 0;
    float convFloat = strtof(str.c_str(), NULL);
    if (errno == ERANGE) {
        std::cerr << "float overflow" << std::endl;
    }
    char    convChar = static_cast<char>(convFloat);
	int		convInt = static_cast<int>(convFloat);
	double	convDouble = static_cast<double>(convFloat);
	display_converted(convChar, convInt, convFloat, convDouble);
}

static void convert_double(std::string str) {
    errno = 0;
    double convDouble = strtod(str.c_str(), NULL);
    if (errno == ERANGE) {
        std::cerr << "double overflow" << std::endl;
    }
    char    convChar = static_cast<char>(convDouble);
	int		convInt = static_cast<int>(convDouble);
	float	convFloat = static_cast<float>(convInt);
	display_converted(convChar, convInt, convFloat, convDouble);
}

void Converter::Convert(std::string const &str) {
    if (is_inf(str)) {
        convert_inf(str);
        return ;
    }
    int scalar = get_scalar(str);
    switch (scalar) {
        case CHAR:
            convert_char(str);
            break;
        case INT:
            convert_int(str);
            break;
        case FLOAT:
            convert_float(str);
            break;
        case DOUBLE:
            convert_double(str);
            break;
        default:
            std::cout << "Invalid input." << std::endl;
    }
}