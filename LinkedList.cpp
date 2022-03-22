#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList()
{
    head = nullptr;
}

void LinkedList::Add(int element)
{
    Unit *newUnit = new Unit;

    newUnit->data = element;
    newUnit->next = nullptr;

    if(head == nullptr)
    {
        head = newUnit;
        std::cout << "Head added" << std::endl;
    }
    else
    {
        std::cout << "Added" << std::endl;
        Unit *current = head;

        while(current->next != nullptr)
            current = current->next;

        current->next = newUnit;
    }
}

void LinkedList::Print()
{
    Unit *current = head;

    while (current != nullptr)
    {
        std::cout << current->data << std::endl;
        current = current->next;
    }
}