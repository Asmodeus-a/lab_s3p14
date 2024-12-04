#include <iostream>
#include <vector>
#include "Phone.h"
#include "LandlinePhone.h"
#include "MobilePhone.h"

void displayMenu() {
    std::cout << "1. Добавить телефон" << std::endl;
    std::cout << "2. Показать информацию обо всех телефонах" << std::endl;
    std::cout << "3. Изменить свойства телефона" << std::endl;
    std::cout << "0. Выход" << std::endl;
}

void addPhone(std::vector<Phone*>& phones) {
    int choice;
    std::string model;
    double price;

    std::cout << "Выберите тип телефона (1 - Стационарный, 2 - Мобильный): ";
    std::cin >> choice;
    std::cout << "Введите модель: ";
    std::cin >> model;
    std::cout << "Введите цену: ";
    std::cin >> price;

    if (choice == 1) {
        bool hasAnsweringMachine;
        std::cout << "Есть автоответчик? (1 - Да, 0 - Нет): ";
        std::cin >> hasAnsweringMachine;
        phones.push_back(new LandlinePhone(model, price, hasAnsweringMachine));
    }

    else if (choice == 2) {
        double minutesIncluded;
        std::cout << "Введите количество включенных минут: ";
        std::cin >> minutesIncluded;
        phones.push_back(new MobilePhone(model, price, minutesIncluded));
    } else {
        std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
    }
}

void showPhones(const std::vector<Phone*>& phones) {
    if (phones.empty()) {
        std::cout << "Список телефонов пуст." << std::endl;
        return;
    }
    for (size_t i = 0; i < phones.size(); ++i) {
        std::cout << "Телефон #" << i + 1 << ": ";
        phones[i]->displayInfo();
    }
}

void modifyPhone(Phone* phone) {
    if (LandlinePhone* landline = dynamic_cast<LandlinePhone*>(phone)) {
        bool hasAnsweringMachine;
        std::cout << "Измените наличие автоответчика (1 - Да, 0 - Нет): ";
        std::cin >> hasAnsweringMachine;
        landline->setHasAnsweringMachine(hasAnsweringMachine);
    } else if (MobilePhone* mobile = dynamic_cast<MobilePhone*>(phone)) {
        double minutesIncluded;
        std::cout << "Измените количество включенных минут: ";
        std::cin >> minutesIncluded;
        mobile->setMinutesIncluded(minutesIncluded);
    }
}

int main() {
    std::vector<Phone*> phones;
    int choice;

    do {
        displayMenu();
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addPhone(phones);
                break;
            case 2:
                showPhones(phones);
                break;
            case 3: {
                int index;
                std::cout << "Введите номер телефона для изменения: ";
                std::cin >> index;
                if (index > 0 && index <= phones.size()) {
                    modifyPhone(phones[index - 1]);
                } else {
                    std::cout << "Неверный номер телефона." << std::endl;
                }
                break;
            }
            case 0:
                std::cout << "Выход..." << std::endl;
                break;
            default:
                std::cout << "Неверный выбор. Пожалуйста, выберите снова." << std::endl;
        }
    } while (choice != 0);

    for (Phone* phone : phones) {
        delete phone; // Освобождение памяти
    }

    return 0;
}

