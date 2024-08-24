#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>

int main()
{
    std::vector<int> vec(5);
    std::deque<int> deque;

    for (size_t i = 1; i <= 5; ++i) {
        vec.push_back(i);
        deque.push_back(i);
        deque.push_front(i);
    }

    try {
        std::cout << "\nNumber: \033[0;32m"<< ::easyfind(vec, 5) << "\033[0m" << std::endl;
        std::cout << "Number: \033[0;32m"<< ::easyfind(deque, 3) << "\033[0m" << std::endl;
        std::cout << "Number: \033[0;32m" << ::easyfind(deque, 6) << "\033[0m" << std::endl;
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n\033[3;34m" << "Deque elements: \n";
    for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Vector elements: \n";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n\n";

    return 0;
}
