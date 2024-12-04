#include "Phone.h"
#include <iostream>

Phone::Phone(const std::string& model, double price) : model(model), price(price) {}

void Phone::displayInfo() const {
    std::cout << "Модель: " << model << ", Цена: " << price << std::endl;
}

double Phone::getPrice() const {
    return price;
}
