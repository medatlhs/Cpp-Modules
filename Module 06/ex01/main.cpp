#include "./Serializer.hpp"

int main() {
    Data data;
    data.name = "LMDNDN";
    data.age = 24;

    std::cout << "address of data: " << &data << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "raw data: " << raw << std::endl;

    Data *dataPtr = Serializer::deserialize(raw);
    std::cout << "value of dataPtr: " << dataPtr << std::endl;
    
    std::cout << "#Accessing data from dataPtr:\n";
    std::cout << "name: " << dataPtr->name << " age: " << dataPtr->age << std::endl;
    return 0;
}
