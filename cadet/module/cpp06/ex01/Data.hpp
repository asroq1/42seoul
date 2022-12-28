#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

typedef struct Data {
    int a;
    double b;
    char c;

} Data;

uintptr_t serialize(Data *ptr) { return reinterpret_cast<uintptr_t>(ptr); }
Data *deserialize(uintptr_t raw) { return reinterpret_cast<Data *>(raw); }

#endif
