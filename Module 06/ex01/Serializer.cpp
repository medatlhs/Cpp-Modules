#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer &) {}
Serializer &Serializer::operator=(Serializer const &) { return *this; }
Serializer::~Serializer() { }

my_uintptr_t Serializer::serialize(Data *ptr) {
    my_uintptr_t raw = reinterpret_cast<my_uintptr_t>(ptr);
    return raw;
}

Data* Serializer::deserialize(my_uintptr_t raw) {
    Data *data = reinterpret_cast<Data *>(raw);
    return data;
}
