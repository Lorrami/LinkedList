#include <iostream>
#include "LinkedList.h"

int main()
{
    LinkedList<std::string> myList;
    myList.Add("Red");
    myList.Add("Green");
    myList.Add("Blue");
    //myList.Remove("Red");
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        if (*it == "Green") {
            myList.InsertAfter(it, "Imposter");
        }
        if (*it == "Red") {
            myList.RemoveAfter(it);
        }
    }
    std::cout << myList;


    LinkedList<int> testList;
    /*testList.Add(1);
    testList.Add(2);
    testList.Add(3);
    testList.Add(4);
     */

    LinkedList<int> newTestList;
    newTestList.Add(5);
    newTestList.Add(6);
    newTestList.Add(7);

    testList = newTestList;

    std::cout << newTestList;

    return 777;
}