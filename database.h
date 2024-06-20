#pragma once
#include <exception>
#include <iostream>
#include <vector>



class Data {
public:
    struct Chat;

    struct User { // структура для введения аккаунта в базу(вектор)
        std::string login = {};
        std::string password = {};
        std::string name = {};
        std::vector<Data::Chat*> chats = {};

        void display_chats(); // вывод доступных личных чатов
    };

    struct Chat {
        struct Message { // сообщение
            User* user_identfier = nullptr;
            std::string content = {};   // что отправил
        };

        std::vector<Message> messages = {}; // все сообщения ЭТОГО чата
        std::vector<Data::User*> users = {};      // ссылки на всех пользователей которые участвуют в этом чате

        void display(); // показать сообщения из чата в формате:
        // <Пользователь>:
        //     <текст>
    };

    Chat* selected_chat = nullptr; // чат который выбрал пользователь
    User* selected_user = nullptr; // пользователь которого выбрал

    std::vector<User> database; // база(вектор) в которой хранятся данные пользователей
    std::vector<Chat> chats; // вектор в котором хранятся все чаты
    Chat main_chat;

    Data(); // тестовый аккаунт
    void addUser(); // Добавление аккаунта
    bool loginUser(); // вход в уже существующий аккаунт
    void logoutUser(); // разлогинить текущего пользователя и убрать выбранный чат
    void identified(); // пишет имя аккаунта (в основном для тестов)
    void users(); // пишет кто ещё существует в сети не считая аккаунт на котором ты сидишь
    bool create_chat(); // текущий пользователь создает чат с другим пользователем
    void chatting(); //работа с текущим пользователем и выбранным чатом
    void select_main_chat();
    void user_select_chat(); // выбор с кем открыть чат
};