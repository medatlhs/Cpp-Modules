#pragma once

#include <iostream>
#include <cstdint>
#include <string>

struct Data {
    std::string username;
};


class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &copy);
        Serializer &operator=(Serializer const &);
        ~Serializer();

    public:
    static uintptr_t    serialize(Data* ptr);
    static Data*        deserialize(uintptr_t raw);
};
