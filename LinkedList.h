#pragma once

#include <iostream>
#include <ostream>
#include "Unit.h"

template <typename T>
class LinkedList
{
private:
    int m_Count = 0;
public:
    Unit<T> *head;
    LinkedList();
    ~LinkedList();
    int Size();
    void Add(const T& element);
    void Remove(const T& element);

    template<typename T>
    friend std::ostream& operator << (std::ostream &stream, const LinkedList& list);
};
template<typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
}
template<typename T>
LinkedList<T>::~LinkedList()
{
    Unit<T> *current = head;

    while(current != nullptr)
    {
        Unit<T> *previous = current;
        current = current->next;
        delete previous;
    }
}

template <typename T>
int LinkedList<T>::Size()
{
    return m_Count;
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
    }
    m_Count++;
}
template<typename T>
void LinkedList<T>::Remove(const T& element)
{
    Unit<T> *current = head;
    Unit<T> *previous = nullptr;
    while(current->data != element && current != nullptr)
    {
        previous = current;
        current = current->next;
    }
    if(previous == nullptr)
    {
        head = current->next;
        delete current;
        m_Count--;
    }
    else
    {
        previous->next = current->next;
        delete current;
        m_Count--;
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list)
{
    Unit<T> *current = list.head;

    while (current != nullptr)
    {
        os << current->data << std::endl;
        current = current->next;
    }
    return os;
}