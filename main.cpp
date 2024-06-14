#include "database.h"
#include "chatfunctions.h"
using namespace std;
// 1. Спросить он хочет войти или зарегестрироваться
// 2. Получить хотелку 
// 3. if reg -> получить логин, пароль, имя и отдать в дата базу чтобы создать нового пользователя
//    else -> проверить логин и пароль


int main() {
    Data database {};

    while (true) {
        bool authorised = false;
        cout << "Welcome to offline chat" << endl;
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


        while (authorised) {
            std::cout << "Menu" << std::endl;
            std::cout << "1 - создать (не работает)" << std::endl;
            std::cout << "2 - открыть лс (не работает)" << std::endl;
            std::cout << "3 - открыть общий (не работает)" << std::endl;
            std::cout << "4 - профиль(проверка на аккаунт)" << std::endl;
            std::cout << "5 - узнать какие есть пользователи" << std::endl;
            std::cout << "6 - выйти из аккаунта" << std::endl;
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
                    database.identified();
                    break;
                }
                case 5: {
                    cout << "Заглушка, дальше ничего нет =)" << endl;
                    database.users();
                    break;
                }
                case 6: {
                    cout << "Выйти из аккаунта" << endl;
                    authorised = false;
                    break;
                }
            }
        }
    }
    return 0;
}