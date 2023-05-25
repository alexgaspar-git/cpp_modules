#include "easyfind.hpp"

const char *ValueNotFoundException::what() const throw() {
    return "Value not found.";
} 

template <typename T> typename T::iterator easyfind(T &t, int n) {
    typename T::iterator it = t.begin();
    while (it != t.end()) {
        if (*it == n)
            return it;
        it++;
    }
    throw ValueNotFoundException();
}
