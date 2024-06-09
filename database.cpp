#include "database.h"

template <typename T>
Data<T>::Data(size_t length) {
    database = new T[length] {};
    size = length;
}

template <typename T>
Data<T>::Create(size_t login, size_t password, size_t name) {
    cout << "Напишите будущий логин:";
    cin >> login;
    database = login;
}