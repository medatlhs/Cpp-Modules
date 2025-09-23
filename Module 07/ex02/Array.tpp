#include "Array.hpp"
#include <iostream>

template <typename T>
Array<T>::Array() : data(NULL), len(0) {
    std::cout << "default constructor called\n";
}

template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]), len(n) {
    std::cout << "parameterized constructor called\n";
}

template <typename T>
Array<T>::Array(const Array& other) : data(new T[other.len]), len(other.len) {
    std::cout << "copy constructor called\n";
    for (unsigned int i = 0; i < len; i++)
        data[i] = other.data[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    std::cout << "assigning operator overload called\n";
    if (this != &other) {
        delete[] data;
        len = other.len;
        data = new T[len];
        for (unsigned int i = 0; i < len; i++)
            data[i] = other.data[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    std::cout << "deconstructor called\n";
    delete[] data;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= len)
        throw std::out_of_range("Index out of bounds");
    return data[index];
}
