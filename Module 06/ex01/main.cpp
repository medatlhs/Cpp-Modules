#include "./Serializer.hpp"

int main() {
    Data data;
    data.username = "moait-la";

    std::cout << "# Data Before Serialization: ";
    std::cout << "data.username = " << data.username << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "raw data: " << raw << std::endl;

    Data *dataPtr = Serializer::deserialize(raw);
    std::cout << "value of dataPtr: " << dataPtr << std::endl;
    
    std::cout << "# Data after Serialization: ";
    std::cout << "data.username = " << dataPtr->username << std::endl;

    return 0;
}
