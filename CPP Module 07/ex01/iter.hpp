#pragma once

#include <iostream>

template<typename T>
void printArr(T& d)
{
    std::cout << d << std::endl;
}

template<typename T>
void squareOfN(T& n)
{
    n *= n;
}

template<typename T>
void iter(T* array, size_t n, void (*func)(T &))
{
    for (size_t i = 0; i < n; ++i) {
        func(array[i]);
    }
}
