#include "Bat.h"

Bat::Bat(const char* name, int age, int gestationDays, double wingspan)
    : Animal(name, age), Mammal(name, age, gestationDays), Bird(name, age, wingspan, true) {}

Bat::Bat(const Bat& other)
    : Animal(other), Mammal(other), Bird(other) {}

Bat& Bat::operator=(const Bat& other) {
    Mammal::operator=(other);
    Bird::operator=(other);
    return *this;
}

const char* Bat::makeSound() const {
    return "Пи-пи";
}

const char* Bat::getSpecies() const {
    return "Летучая мышь";
}