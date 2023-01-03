#include "Data.hpp"

uintptr_t serialize(Data *ptr) { return reinterpret_cast<uintptr_t>(ptr); }
Data *deserialize(uintptr_t raw) { return reinterpret_cast<Data *>(raw); }

int main() {
    Data data;
    Data *tmp;
    uintptr_t ptr = 0;

    data.a = 42;
    data.b = 42.0;
    data.c = 'a';

    std::cout << "data adress : " << &data << std::endl;
    std::cout << "tmp adress : " << &tmp << std::endl;
    std::cout << "ptr adress : " << &ptr << std::endl;
    std::cout << std::endl;

    std::cout << "data a: " << data.a << std::endl;
    std::cout << "data b: " << data.b << std::endl;
    std::cout << "data c: " << data.c << std::endl;
    std::cout << std::endl;

    ptr = serialize(&data);

    tmp = deserialize(ptr);
    std::cout << "tmp a : " << tmp->a << std::endl;
    std::cout << "tmp b : " << tmp->b << std::endl;
    std::cout << "tmp c : " << tmp->c << std::endl;
    std::cout << std::endl;

    return 0;
}
