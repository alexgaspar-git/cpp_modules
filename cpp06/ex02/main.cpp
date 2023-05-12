#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

#include <cstdlib>
#include <iostream>

Base *generate() {
    srand(time(NULL));
    switch (rand() % 3) {
        case 0:
            std::cout << "A generated" << std::endl;
            return new A();
        case 1:
            std::cout << "B generated" << std::endl;
            return new B();
        case 2:
            std::cout << "C generated" << std::endl;
            return new C();
        default:
            std::cout << "tf happend" << std::endl;
            return NULL;
    }
}

void identify(Base *p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    }
}

void identify(Base &p) {
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)a;
        return;
    } catch (std::exception &e) {}
    try {
        B& b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        (void)b;
        return;
    } catch (std::exception &e) {}
    try {
        C& c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        (void)c;
        return;
    } catch (std::exception &e) {}
}


int main() {
    Base* p = generate();
    identify(p);
    identify(*p);
    delete p;
    return 0;
}