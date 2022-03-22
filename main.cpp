#include <iostream>
#include "LinkedList.h"

int main()
{
    LinkedList<std::string> myList;

    myList.Add("Red");
    myList.Add("Green");
    myList.Add("Blue");

    myList.Remove("Red");
    std::cout << myList;
    std::cout << myList.Size();

    for (LinkedList<std::string>::Iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << std::endl;

    return 777;
}