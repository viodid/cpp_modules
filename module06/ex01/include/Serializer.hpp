#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <iostream>
#include <stdint.h>
#include <string>

typedef struct s_data {
    int content;
} Data;

class Serializer {
private:
    Serializer();
    Serializer(const Serializer& cp);
    ~Serializer();

    Serializer& operator=(const Serializer& cp);

public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif
