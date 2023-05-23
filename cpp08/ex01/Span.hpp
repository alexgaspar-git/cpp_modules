#ifndef SPAN_HPP
#define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <exception>

class Span {
private:
	unsigned int _nIntegers;
	std::vector<int> _intContainer;
public:
	Span(unsigned int nInts);

	Span();
	Span(const Span &other);
	~Span();
	Span & operator=(const Span &other);

	void addNumber(int n);
	void addNumbers(const std::vector<int> &vec);

	void printNumbers();

	int shortestSpan() const;
	int longestSpan() const;

	class ContainerFullException : public std::exception {
	public:
		const char *what() const throw();
	};

	class SpanSizeException : public std::exception {
	public:
		const char *what() const throw();
	};
};

#endif