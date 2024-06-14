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
    current_name = user.name;
    database.push_back(user);
    pointer++;
}

bool Data::loginUser() {
    std::string login {};
    std::string password {};
    cout << "write your login" << endl;
    cin >> login;
    cout << "write your password" << endl;
    cin >> password;

    for (auto user : database) {
        if (user.login == login && user.password == password){
            current_name = user.name;
            return true;
        }
    }

    cout << "Failed log in, login or password error" << endl;
    return false;
}

void Data::identified(){
    cout << current_name << endl;
}

void Data::users(){
    for (auto user : database) {
        if (user.name != current_name) {
            cout << user.name << endl;
        }
    }
}


