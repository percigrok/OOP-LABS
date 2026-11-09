#include "Lion.h"

#include <iostream>

Lion::Lion(const char* name, int age, int gestationDays)
    : Animal(name, age), Mammal(name, age, gestationDays) {}

const char* Lion::makeSound() const {
    return "Рррр";
}

const char* Lion::getSpecies() const {
    return "Лев";
}

void Lion::move() const {
    std::cout << name << " бегает\n";
}