#include "database.h"
#include <iostream>
using namespace std;

Data::Data() {
    database.push_back(User{
        "admin",
        "admin",
        "admin"
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
    pointer++;
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
            return true;
        }
        else {
            cout << "Failed log in, login or password error" << endl;
            return false;
        }
    }

    return false;
}

// Baza -> User[] -+-> login
//                 |
//                 +-> password
//                 |
//                 +-> name


