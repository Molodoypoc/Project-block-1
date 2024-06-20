#include "database.h"
#include <iostream>
using namespace std;

Data::Data() {
    database.push_back(User{
        "admin",
        "admin",
        "Admin"
    });

}

void Data::addUser() {
    std::string login {};
    std::string password {};
    std::string name {};

    cout << "write your login" << endl;
    cin >> login;
    cout << "write your password" << endl;
    cin >> password;
    cout << "write your name" << endl;
    cin >> name;

    User user = {
        .login = login,
        .password = password,
        .name = name,
    };
    database.push_back(user);
    selected_user = &database[database.size() - 1];
}

bool Data::loginUser() {
    std::string login {};
    std::string password {};
    cout << "write your login" << endl;
    cin >> login;
    cout << "write your password" << endl;
    cin >> password;

    for (User& user : database) {
        if (user.login == login && user.password == password){
            selected_user = &user;
            return true;
        }
    }

    cout << "Failed log in, login or password error" << endl;

    return false;
}

void Data::logoutUser(){
    selected_user = nullptr;
    selected_chat = nullptr;
}

void Data::identified(){
    cout << selected_user->name << endl;
}

void Data::users(){
    for (User& user : database) {
        if (&user != selected_user) {
            cout << user.name << endl;
        }
    }
}

void Data::Chat::display() {
    for (const Message& message : messages) {
        cout << "From: " << message.user_identfier->name << endl;
        cout << "\t" << message.content << endl;
    }
}

bool Data::create_chat() {

    User user;
    string selected_name;
    users();
    cout << "Выберите пользователя с которым откроете чат" << endl;
    cin >> selected_name;

    for (User& user : database) {
        if (user.name == selected_name) {

            Chat chat {};
            chats.push_back(chat);

            selected_chat = &chats[chats.size() - 1];

            selected_user->chats.push_back(selected_chat);
            user.chats.push_back(selected_chat);
            selected_chat->users.push_back(selected_user);
            selected_chat->users.push_back(&user);
            return true;
        }
    }

    cout << "Нет такого пользователя" << endl;
    return false;
}

void Data::chatting() {
    selected_chat->display();
    while (true) {
        Chat chat {};
        cout << "Выберите функцию: 1 - отправить сообщение. 2 - выйти из чата." << endl;
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Напишите сообщение которое хотите отправить" << endl;
                string message;
                cin >> message;
                Chat::Message message_struct = { selected_user, message };
                selected_chat->messages.push_back(message_struct);
                break;
            }
            case 2: {
                cout << "Вы вышли из чата" << endl;
                selected_chat = nullptr;
                return;
            }
            default: {
                cout << "Это не вариант" << endl;
                string temp = "";
                cin >> temp;
                break;
            }
        }
    }
}

void Data::User::display_chats() {
    for (size_t i = 0; i < chats.size(); i++) {
        cout << i + 1 << " ";
        for (const Data::User* user : chats[i]->users) {
            if (user == nullptr) {
                continue;
            }

            if (user != this) {
                cout << user->name << ", ";
            }
        }

        cout << endl;
    }
}

void Data::user_select_chat() {

    selected_user->display_chats();

    cout << "Введите число:" << endl;
    size_t selected = 0;
    cin >> selected;
    if (selected > chats.size()) {
        cout << "Неправильно введено число" << endl;
        return;
    }

    selected_chat = &chats[selected - 1];
    cout << "Вы выбрали чат" << endl;
    chatting();
}