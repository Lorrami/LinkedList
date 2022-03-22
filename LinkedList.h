#pragma once

#include <iostream>
#include "Unit.h"

template <typename T>
class LinkedList
{
private:
    Unit<T> *head;
public:
    LinkedList();
    ~LinkedList();
    void Add(const T& element);
    void Delete();
    void Print();
};

template<typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
}
template<typename T>
LinkedList<T>::~LinkedList()
{
    delete *head;
}
template<typename T>
void LinkedList<T>::Add(const T& element)
{
    Unit<T> *newUnit = new Unit<T>;

    newUnit->data = element;
    newUnit->next = nullptr;

    if(head == nullptr)
    {
        head = newUnit;
    }
    else
    {
        Unit<T> *current = head;

        while(current->next != nullptr)
            current = current->next;

        current->next = newUnit;
        delete *current;
    }
    delete *newUnit;
}

template<typename T>
void LinkedList<T>::Delete()
{

}

template<typename T>
void LinkedList<T>::Print()
{
    Unit<T> *current = head;

    while (current != nullptr)
    {
        std::cout << current->data << std::endl;
        current = current->next;
    }
}