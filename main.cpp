#include "LinkedList.h"

int main()
{
    LinkedList<std::string> myList;

    myList.Add("First");
    myList.Add("Second");
    myList.Add("Third");

    myList.Print();
    return 777;
}