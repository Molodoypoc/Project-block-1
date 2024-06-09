#pragma once
#include <exception>
#include <iostream>

template <typename T>
class Data
{
    private:
    T* database;
    int size;

    public:
    Data(size_t lenght);
    Create(size_t login, size_t password, size_t name);
};