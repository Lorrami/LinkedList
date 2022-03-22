#pragma once

#include <iostream>
#include <ostream>
#include "Unit.h"

template <typename T>
class LinkedList {

private:

    int m_Count = 0;

public:

    Unit<T> *head;

    LinkedList();

    ~LinkedList();

    int Size();

    void Add(const T &element);

    void Remove(const T &element);

public:

    template<typename DefType>
    friend std::ostream &operator<<(std::ostream &stream, const LinkedList &list);

private:

    template<typename Type>
    class ListIterator
    {
        public:
            Unit<T> *currentUnit;
            explicit ListIterator(Unit<T> *currentUnit) : currentUnit(currentUnit){}

            ListIterator& operator++()
            {
                currentUnit = currentUnit->next;
                return *this;
            }
            Type *operator->()
            {
                return &currentUnit->data;
            }

            Type &operator*()
            {
                return currentUnit->data;
            }
            bool operator==(const ListIterator &other)
            {
                return currentUnit == other.currentUnit;
            }
            bool operator!=(const ListIterator &other)
            {
                return currentUnit != other.currentUnit;
            }
    };

public:

    using Iterator = ListIterator<T>;

    Iterator begin()
    {
        return Iterator(head);
    }

    Iterator end()
    {
        return Iterator(nullptr);
    }
    void InsertByIterator(Iterator iterator, T element);
    void RemoveByIterator(Iterator iterator);
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
    auto *newUnit = new Unit<T>;

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
template<typename T>
void LinkedList<T>::InsertByIterator(Iterator iterator, T element)
{
    Unit<T> *currentUnit = iterator.currentUnit;
    Unit<T> *newUnit = new Unit<T>;

    if (currentUnit->next == nullptr)
    {
        newUnit->data = element;
        currentUnit->next = newUnit;
        newUnit->next = nullptr;
    }
    else
    {
        newUnit->data = element;
        auto t = currentUnit->next;
        currentUnit->next = newUnit;
        newUnit->next = t;
    }
}
template<typename T>
void LinkedList<T>::RemoveByIterator(Iterator iterator)
{
    //Unit<T> currentUnit;
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