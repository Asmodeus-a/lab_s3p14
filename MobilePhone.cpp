#include "MobilePhone.h"
#include <iostream>

MobilePhone::MobilePhone(const std::string& model, double price, double minutesIncluded)
    : Phone(model, price), minutesIncluded(minutesIncluded) {}

void MobilePhone::displayInfo() const {
    Phone::displayInfo();
    std::cout << "Включенные минуты: " << minutesIncluded << std::endl;
}

double MobilePhone::getMinutesIncluded() const {
    return minutesIncluded;
}

void MobilePhone::setMinutesIncluded(double minutes) {
    minutesIncluded = minutes;
}

