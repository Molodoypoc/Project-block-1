#pragma once
#include <exception>
#include <iostream>
#include "exceptions.h"
#include <vector>

struct User {
    std::string login;
    std::string password;
    std::string name;
};

class Data {
private:
    std::vector<User> database;
    int size;
    int pointer = 0;

public:
    Data();
    void addUser(); // Добавление пользователя
    bool loginUser();
};