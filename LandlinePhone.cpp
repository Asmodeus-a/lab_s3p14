#include "LandlinePhone.h"
#include <iostream>

LandlinePhone::LandlinePhone(const std::string& model, double price, bool hasAnsweringMachine)
    : Phone(model, price), hasAnsweringMachine(hasAnsweringMachine) {}

void LandlinePhone::displayInfo() const {
    Phone::displayInfo();
    std::cout << "Автоответчик: " << (hasAnsweringMachine ? "Есть" : "Нет") << std::endl;
}

bool LandlinePhone::getHasAnsweringMachine() const {
    return hasAnsweringMachine;
}

void LandlinePhone::setHasAnsweringMachine(bool has) {
    hasAnsweringMachine = has;
}
