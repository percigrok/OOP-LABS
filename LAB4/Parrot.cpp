#include "Parrot.h"

#include <iostream>

Parrot::Parrot(const char* name, int age, double wingspan, bool canFly)
    : Animal(name, age), Bird(name, age, wingspan, canFly) {}

const char* Parrot::makeSound() const {
    return "Привет";
}

const char* Parrot::getSpecies() const {
    return "Попугай";
}

void Parrot::move() const {
    std::cout << name << " летает\n";
}