#include "Span.hpp"

Span::Span(unsigned int nInts) : _nIntegers(nInts) {}

Span::Span() {}

Span::Span(const Span &other) : _nIntegers(other._nIntegers), _intContainer(other._intContainer) {
	(void) other;
}

Span::~Span() {}

Span & Span::operator=(const Span &other) {
	(void)other;
	return *this;
}

void Span::addNumber(int n) {
	if (_intContainer.size() >= _nIntegers) {
		throw Span::ContainerFullException();
	} else {
		_intContainer.push_back(n);
	}
}

void Span::addNumbers(const std::vector<int> &vec) {
	if (_intContainer.size() + vec.size() > _nIntegers)
        throw Span::SpanSizeException();
	_intContainer.insert(_intContainer.end(), vec.begin(), vec.end());
}

void Span::printNumbers() {
	for (std::vector<int>::size_type i = 0; i < _intContainer.size(); i++) {
		std::cout << _intContainer[i] << std::endl;
	}
}

static std::vector<int> sortVector(std::vector<int> unsorted) {
	std::vector<int> sorted = unsorted;
	for (std::vector<int>::size_type i = 0; i < sorted.size() - 1; i++) {
		for (std::vector<int>::size_type j = 0; j < sorted.size() - 1; j++) {
			if (sorted[j] > sorted[j + 1])
				std::swap(sorted[j], sorted[j + 1]);
		}
	}
	return sorted;
}

int Span::shortestSpan() const {
	if (_intContainer.size() <= 1) {
		throw Span::SpanSizeException();
	} else {
		std::vector<int> sorted = sortVector(_intContainer);
		return sorted[1] - sorted[0];
	}
}

int Span::longestSpan() const {
	if (_intContainer.size() <= 1) {
		throw Span::SpanSizeException();
	} else {
		std::vector<int> sorted = sortVector(_intContainer);
		int lastNumber = sorted.back();
		return lastNumber - sorted[0];
	}
}

const char *Span::ContainerFullException::what() const throw() {
    return "Container is full.";
}

const char *Span::SpanSizeException::what() const throw() {
    return "not enough numbers to find span";
}