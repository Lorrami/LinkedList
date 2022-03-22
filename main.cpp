#include <iostream>
#include "LinkedList.h"

int main()
{
    LinkedList<std::string> myList;

    myList.Add("Red");
    myList.Add("Green");
    myList.Add("Blue");

    myList.Remove("Green");
    std::cout << myList;
    std::cout << myList.Count();

    return 777;
}