#include "dllist.h"

int main()
{
    DLList<int> list;

    list += 1;
    std::cout << list << std::endl;
    list += 2;
    list += 3;
    list += 4;
    list += 5;
    DLList<int>::Iterator it = list.last();
    while (it != list.end())
    {
        std::cout << *it << " ";
        --it;
    }
    std::cout << std::endl;
    list += 8;
    it = list.begin();
    list += 7;
    while (it != list.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    it = list.last();
    while (it != list.end())
    {
        std::cout << *it << " ";
        --it;
    }

    return 0;
}