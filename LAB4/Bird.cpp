#include "Bird.h"

/**
 * @brief Конструктор с параметрами
 */
Bird::Bird(const char* name, int age, double wingspan, bool canFly)
    : Animal(name, age), wingspan(wingspan), canFly(canFly) {}

/**
 * @brief Копирующий конструктор
 */
Bird::Bird(const Bird& other)
    : Animal(other), wingspan(other.wingspan), canFly(other.canFly) {}

/**
 * @brief Оператор присваивания
 */
Bird& Bird::operator=(const Bird& other) {
    if (this != &other) {
        Animal::operator=(other);
        wingspan = other.wingspan;
        canFly = other.canFly;
    }
    return *this;
}

double Bird::getWingspan() const {
    return wingspan;
}

bool Bird::getCanFly() const {
    return canFly;
}