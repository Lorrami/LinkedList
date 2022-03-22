#pragma once

#include <iostream>
#include <ostream>
#include "Unit.h"

template <typename LinkedList>
class ListIterator
{
public:
    using ValueType = typename LinkedList::ValueType;
    using PointerType = ValueType*;
    using RefernceType = ValueType&;
public:
    ListIterator(PointerType ptr) : m_Ptr(ptr){}
    ListIterator& operator++()
    {
        m_Ptr++;
        return *this;
    }
    ListIterator operator++(int)
    {
        ListIterator iterator = *this;
        ++(*this);
        return iterator;
    }
    ListIterator& operator--()
    {
        m_Ptr--;
        return *this;
    }
    ListIterator operator--(int)
    {
        ListIterator iterator = *this;
        --(*this);
        return iterator;
    }
    RefernceType operator[](int i)
    {
        return *(m_Ptr + i);
    }
    PointerType operator->()
    {
        return m_Ptr;
    }
    RefernceType operator*()
    {
        return *m_Ptr;
    }
    bool operator==(const ListIterator& other) const
    {
        return m_Ptr == other.m_Ptr;
    }
    bool operator!=(const ListIterator& other) const
    {
        return *this != other;
    }
private:
    PointerType m_Ptr;
};

template <typename T>
class LinkedList
{
private:
    int m_Count = 0;
public:
    using ValueType = T;
    using Iterator = ListIterator<LinkedList<T>>;
public:
    Unit<T> *head;
    LinkedList();
    ~LinkedList();
    int Size();
    void Add(const T& element);
    void Remove(const T& element);
public:
    template<typename T>
    friend std::ostream& operator << (std::ostream &stream, const LinkedList& list);
public:
    Iterator begin()
    {
        return Iterator(head);
    }
    Iterator end()
    {
        Unit<T> *current;
        while(current != nullptr)
        {
            current = current->next;
        }
        return Iterator(current);
    }
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