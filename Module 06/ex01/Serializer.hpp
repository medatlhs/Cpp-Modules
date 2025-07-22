#pragma once

#include <iostream>
#include <cstdint>
#include <string>

struct Data {
    std::string name;
    int         age;
};


class Serializer
{
    private:
        Serializer();

    public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};
