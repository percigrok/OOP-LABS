#include "Elephant.h"

Elephant::Elephant(const char* name, int age, int gestationDays)
    : Animal(name, age), Mammal(name, age, gestationDays) {}

const char* Elephant::makeSound() const {
    return "Ту-ту";
}

const char* Elephant::getSpecies() const {
    return "Слон";
}