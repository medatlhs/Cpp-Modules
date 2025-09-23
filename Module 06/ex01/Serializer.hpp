#pragma once

#include <iostream>
#include <string>

typedef unsigned long my_uintptr_t;

struct Data { std::string username; };

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &copy);
        Serializer &operator=(Serializer const &other);
        ~Serializer();

    public:
        static my_uintptr_t serialize(Data* ptr);
        static Data*        deserialize(my_uintptr_t raw);
};
