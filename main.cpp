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
        cout << "Welcome to offline chat" << endl;
        cout << "choice option: 1 - registration, 2 - log in" << endl;
        int choice;
        cin >> choice;
        switch (choice) { // выбор входа в аккаунт или регистрации аккаунта
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


        while (authorised) { // выбор функции
            std::cout << "Menu" << std::endl;
            std::cout << "1 - создать чат" << std::endl;
            std::cout << "2 - открыть лс" << std::endl;
            std::cout << "3 - открыть общий" << std::endl;
            std::cout << "4 - профиль(проверка на аккаунт)" << std::endl;
            std::cout << "5 - узнать какие есть пользователи" << std::endl;
            std::cout << "6 - выйти из аккаунта" << std::endl;
            std::cout << "7 - выйти из программы" << std::endl;
            int choice;
            cin >> choice;
            switch (choice) {
                case 1: {
                    if (database.create_chat()) {
                        database.chatting();
                    } else {
                        cout << "Ввели неправльное имя пользователя" << endl;
                    }
                    break;
                }
                case 2: {
                    database.user_select_chat();
                    break;
                }
                case 3: {
                    database.select_main_chat();
                    break;
                }
                case 4: {
                    cout << "Информация об аккаунте(имя пользователя)" << endl;
                    database.identified();
                    break;
                }
                case 5: {
                    cout << "Зарегистрированные пользователи" << endl;
                    database.users();
                    break;
                }
                case 6: {
                    cout << "Выйти из аккаунта" << endl;
                    authorised = false;
                    database.logoutUser();
                    break;
                }
                case 7: {
                    return 0;
                }
            }
        }
    }
    return 0;
}