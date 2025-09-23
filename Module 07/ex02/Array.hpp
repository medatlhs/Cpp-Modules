#pragma once

template <typename T>
class Array {
    private:
        T* data;
        unsigned int len;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();

        T& operator[](unsigned int index);
};

#include "Array.tpp"
