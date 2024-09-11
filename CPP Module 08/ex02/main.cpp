#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    
    
    std::cout << "\n\n";

    MutantStack<int> kstack;

    kstack.push(1);
    kstack.push(2);
    kstack.push(3);

    std::cout << "iterator\n";

    for (MutantStack<int>::iterator it = kstack.begin(); it != kstack.end(); ++it) {
    std::cout << *it << std::endl;
    }

    std::cout << "reverse iterator\n";

    for (MutantStack<int>::reverse_iterator rit = kstack.rbegin(); rit != kstack.rend(); ++rit) {
    std::cout << *rit << std::endl;
    }

    std::cout << "const iterator\n";

    for (MutantStack<int>::const_iterator cit = kstack.cbegin(); cit != kstack.cend(); ++cit) {
    std::cout << *cit << std::endl;
    }
    
    return 0;
}