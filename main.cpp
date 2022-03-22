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
    std::cout << myList.Size() << std::endl;


    for (auto &value : myList)
        std::cout << value.data() << std::endl;

    return 777;
}