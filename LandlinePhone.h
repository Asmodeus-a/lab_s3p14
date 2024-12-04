#ifndef LANDLINEPHONE_H
#define LANDLINEPHONE_H

#include "Phone.h"

class LandlinePhone : public Phone {
private:
    bool hasAnsweringMachine; // Наличие автоответчика

public:
    LandlinePhone(const std::string& model, double price, bool hasAnsweringMachine);
    void displayInfo() const override; // Переопределение метода отображения информации

    bool getHasAnsweringMachine() const; // Получить наличие автоответчика
    void setHasAnsweringMachine(bool has);
};

#endif
