#pragma once
#include <iostream>

template <typename T>
struct Unit
{
    T data;
    Unit *next;
};