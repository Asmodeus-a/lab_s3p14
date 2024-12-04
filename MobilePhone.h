#ifndef MOBILEPHONE_H
#define MOBILEPHONE_H

#include "Phone.h"

class MobilePhone : public Phone {
private:
    double minutesIncluded; // Количество включенных минут

public:
    MobilePhone(const std::string& model, double price, double minutesIncluded);
    void displayInfo() const override; // Переопределение метода отображения информации

    double getMinutesIncluded() const; // Получить количество включенных минут
    void setMinutesIncluded(double minutes);
};

#endif
