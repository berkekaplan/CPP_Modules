#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data *ds = new Data;
    ds->a = 42;
    ds->b = ds->a * 1e-2;

    std::cout << std::endl << "\033[0;36m-----------------------------------------------" << std::endl;
    std::cout << "\033[0;32mBefore: \033[0m\033[0;36m" << ds << std::endl;
    uintptr_t rawPtr = Serializer::serialize(ds);
    std::cout << "\033[0;31mAfter: \033[0m\033[0;36m" << rawPtr << std::endl;
    std::cout << "-----------------------------------------------" << std::endl << std::endl;
    std::cout << "\033[0;37m-----------------------------------------------" << std::endl;

    Data *tmp = NULL;
    tmp = Serializer::deserialize(rawPtr);
    std::cout << "\033[0;34mBefore: \033[0m\033[0;37m" << tmp << std::endl;
    std::cout << "\033[0;35mtmp->a: \033[0m\033[0;37m" << tmp->a << std::endl;
    std::cout << "\033[0;35mtmp->b: \033[0m\033[0;37m" << tmp->b << std::endl;
    std::cout << "-----------------------------------------------" << std::endl << std::endl;

    delete ds;
    return 0;
}