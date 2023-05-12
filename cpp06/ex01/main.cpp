#include "Data.hpp"
#include "Serialize.h"
#include <iostream>

int main() {
    Data d = {42, 21, 69};
    
    uintptr_t p = serialize(&d);

    Data* q = deserialize(p);

    if (q == &d) {
        std::cout << "Deserialization successful\n";
    } else {
        std::cout << "Deserialization failed\n";
    }
    
    return 0;
}