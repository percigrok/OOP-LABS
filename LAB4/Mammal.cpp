#include "Mammal.h"

/**
 * @brief Конструктор с параметрами
 */
Mammal::Mammal(const char* name, int age, int gestationDays)
    : Animal(name, age), gestationDays(gestationDays), nursing(true) {}

/**
 * @brief Копирующий конструктор
 */
Mammal::Mammal(const Mammal& other)
    : Animal(other), gestationDays(other.gestationDays), nursing(other.nursing) {}

/**
 * @brief Оператор присваивания
 */
Mammal& Mammal::operator=(const Mammal& other) {
    if (this != &other) {
        Animal::operator=(other);
        gestationDays = other.gestationDays;
        nursing = other.nursing;
    }
    return *this;
}

int Mammal::getGestationDays() const {
    return gestationDays;
}

bool Mammal::isNursing() const {
    return nursing;
}