#include "database.h"
using namespace std;
// 1. Спросить он хочет войти или зарегестрироваться
// 2. Получить хотелку 
// 3. if reg -> получить логин, пароль, имя и отдать в дата базу чтобы создать нового пользователя
//    else -> проверить логин и пароль


int main() {
    Data database {};

    while (true) {
        bool authorised = false;
        while (!authorised) {
            cout << "choice option: 1 - registration, 2 - log in" << endl;
            int choice;
            cin >> choice;
            switch (choice) {
                case 1: {
                    database.addUser(); // register
                    authorised = true;
                    break;
                }
                case 2: {
                    authorised = database.loginUser(); // log in
                    break;
                }
            }
        }

        std::cout << "Menu" << std::endl;

        bool loggen_in = true;
        while (loggen_in) {
            std::cout << "1 - создать" << std::endl;
            std::cout << "2 - открыть лс" << std::endl;
            std::cout << "3 - открыть общий" << std::endl;
            std::cout << "4 - выйти" << std::endl;
            int choice;
            cin >> choice;
            switch (choice) {
                case 1: {
                    cout << "Заглушка, дальше ничего нет =)" << endl;
                    break;
                }
                case 2: {
                    cout << "Заглушка, дальше ничего нет =)" << endl;
                    break;
                }
                case 3: {
                    cout << "Заглушка, дальше ничего нет =)" << endl;
                    break;
                }
                case 4: {
                    cout << "Заглушка, дальше ничего нет =)" << endl;
                    break;
                }
            }
        }
    }

    return 0;
}

// git add .
// git commit -a
// <Текст который будет в коммите>