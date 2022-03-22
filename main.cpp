#include <iostream>
#include "LinkedList.h"

int main()
{
    LinkedList<std::string> myList;

    myList.Add("Red");
    myList.Add("Green");
    myList.Add("Blue");

    //myList.Remove("Red");

    for (auto it = myList.begin(); it != myList.end(); ++it)
    {
        if (*it == "Green")
            myList.InsertByIterator(it, "Imposter");
    }

    std::cout << myList;

    return 777;
}