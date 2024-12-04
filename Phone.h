#ifndef PHONE_H
#define PHONE_H

#include <string>

class Phone {
protected:
    std::string model;    // Модель телефона
    double price;         // Цена телефона

public:
    Phone(const std::string& model, double price);
    virtual ~Phone() {}

    virtual void displayInfo() const; // Виртуальная функция для отображения информации
    double getPrice() const;           // Метод для получения цены
};

#endif
