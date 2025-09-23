#include "./Serializer.hpp"

int main() {
    Data data;
    data.username = "moait-la";

    std::cout << "# Data Before Serialization: ";
    std::cout << "data.username = " << data.username << std::endl;

    my_uintptr_t raw = Serializer::serialize(&data);
    Data *dataPtr = Serializer::deserialize(raw);
    
    std::cout << "# Data after Deserialization: ";
    std::cout << "data.username = " << dataPtr->username << std::endl;

    return 0;
}
