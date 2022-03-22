#include <iostream>
#include "LinkedList.h"

int main()
{
    LinkedList<int> myList;

    myList.Add(1);
    myList.Add(1);
    myList.Add(3);

    std::cout << myList;

    return 777;
}