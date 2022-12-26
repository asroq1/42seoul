#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <stdint.h>

class Data {
  private:
    /* data */

  public:
    Data();
    Data(const Data &ref);
    ~Data();

    Data &operator=(const Data &ref);
    Data *deserialize(uintptr_t raw) {}
};

#endif
