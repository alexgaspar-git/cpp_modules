#include "BitcoinExchange.hpp"

// ###################

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}

Date Date::operator--(int) {
    Date temp(*this);
    day--;
    if (day < 1) {
        month--;
        if (month < 1) {
            month = 12;
            year--;
        }
        day = 31;
    }
    return temp;
}

// ###################

BitcoinExchange::BitcoinExchange() : _date(""), _rateVal(0) {
    std::ifstream data("data.csv");

    if (!data) {
        std::cout << "data.csv not found" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    while (std::getline(data, line)) {
        std::size_t commaPos = line.find(",");
        std::string date = line.substr(0, commaPos);
        float rate;
        std::istringstream(line.substr(commaPos + 1)) >> rate;
        _data[date] = std::make_pair(rate, true);
    }

    data.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _data(other._data) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this == &other)
        return *this;
    _data = other._data;
    return *this;
}

// ###################

bool BitcoinExchange::parseDate(std::string &line) {
    int i = 0;
    while (std::isspace(line[i]))
        i++;
    std::string year = line.substr(i, 4);
    if (atoi(year.c_str()) > 2022 || atoi(year.c_str()) < 2009)
        return false;
    i += 4;
    if (line[i] != '-')
        return false;
    i++;
    std::string month = line.substr(i, 2);
    if (atoi(month.c_str()) > 12 || atoi(month.c_str()) < 1)
        return false;
    i += 2;
    if (line[i] != '-')
        return false;
    i++;
    std::string day = line.substr(i, 2);
    if (atoi(day.c_str()) > 31 || atoi(day.c_str()) < 1)
        return false;
    if (year == "2009" && month == "01" && day == "01")
        return false;
    _date = year + "-" + month + "-" + day;
    return true;
}

static bool isDouble(std::string &str) {
    std::istringstream iss(str);
    double value;
    return (iss >> value) && (iss.eof());
}

bool BitcoinExchange::parseRate(std::string &line) {
    if (!isDouble(line))
        return false;
    double num = atof(line.c_str());
    if (num > 10000 || num < 0)
        return false;
    _rateVal = num;
    return true;
}

void BitcoinExchange::parseLine(std::string &line) {
    std::size_t sepPos = line.find("|");
    if (sepPos == std::string::npos)
        throw InvalidFormatException();

    std::string date = line.substr(0, sepPos);

    if (!parseDate(date))
        throw InvalidDateException();

    std::string rate = line.substr(sepPos + 1);

    if (!parseRate(rate))
        throw InvalidRateValueException();
}

static std::string dateToStr(const Date &date) {
    std::ostringstream oss;

    oss << date.year << "-";

    if (date.month < 10) {
        oss << "0";
    }
    oss << date.month << "-";

    if (date.day < 10) {
        oss << "0";
    }
    oss << date.day;

    return oss.str();
}
static Date strToDate(const std::string &str) {
    int year, month, day;
    char dash1, dash2;
    std::istringstream iss(str);
    iss >> year >> dash1 >> month >> dash2 >> day;
    return Date(year, month, day);
}

std::string BitcoinExchange::getLowestDate(std::string &date) {
    Date sDate = strToDate(date);
    std::pair<double, bool> exist = _data[dateToStr(sDate)];

    while (!exist.second) {
        sDate--;
        exist = _data[dateToStr(sDate)];
    }

    return dateToStr(sDate);
}

void BitcoinExchange::calculateValue(std::ifstream &input) {
    std::string line;
    while (std::getline(input, line)) {
        try {
            parseLine(line);
            std::string lowestDate = getLowestDate(_date);
            std::cout << _date << " => " << _rateVal << " = " << _data[lowestDate].first * _rateVal << std::endl;
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
}

const char *BitcoinExchange::InvalidDateException::what() const throw() {
    return "Invalid date format, please only use dates between 2009 and 2022 in the YYYY-MM-DD format";
}

const char *BitcoinExchange::InvalidRateValueException::what() const throw() {
    return "Your rate value must be a valid float between 0 and 10000";
}

const char *BitcoinExchange::InvalidFormatException::what() const throw() {
    return "Invalid data format, please use date | value";
}

