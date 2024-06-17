#pragma once
#include <exception>
#include <iostream>
#include "exceptions.h"
#include <vector>

struct User { // структура для введения аккаунта в базу(вектор)
    std::string login;
    std::string password;
    std::string name;
};

class Data {
private:
    std::vector<User> database; // база(вектор) в которой хранятся данные пользователей
    int pointer = 1; // просто счётчик созданных аккаунтов(1 потому что есть тестовый ак.)
    std::string current_name = "0"; // текущее имя

public:
    Data(); // тестовый аккаунт
    void addUser(); // Добавление аккаунта
    bool loginUser(); // вход в уже существующий аккаунт
    void identified(); // пишет имя аккаунта (в основном для тестов)
    void users(); // пишет кто ещё существует в сети не считая аккаунт на котором ты сидишь
};