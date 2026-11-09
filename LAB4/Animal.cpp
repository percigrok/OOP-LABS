#include "Animal.h"
 
#include <cstring>
#include <iostream>
 
int Animal::totalCount = 0;
 
/**
 * @brief Копирует имя в новую динамическую память
 */
void Animal::setName(const char* newName) {
    delete[] name;
    name = new char[std::strlen(newName) + 1];
    std::strcpy(name, newName);
}

/**
 * @brief Конструктор с параметрами
 */
Animal::Animal(const char* name, int age) : name(nullptr), age(age) {
    setName(name);
    totalCount++;
}
 
/**
 * @brief Копирующий конструктор (глубокое копирование имени)
 */
Animal::Animal(const Animal& other) : name(nullptr), age(other.age) {
    setName(other.name);
    totalCount++;
}
 
/**
 * @brief Оператор присваивания (глубокое копирование имени)
 */
Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        age = other.age;
        setName(other.name);
    }
    return *this;
}

/**
 * @brief Деструктор освобождает имя и уменьшает счётчик
 */
Animal::~Animal() {
    delete[] name;
    totalCount--;
}
 
/**
 * @brief Движение по умолчанию
 */
void Animal::move() const {
    std::cout << name << " двигается\n";
}
 
const char* Animal::getName() const {
    return name;
}
 
int Animal::getAge() const {
    return age;
}
 
int Animal::getTotalCount() {
    return totalCount;
}

/**
 * @brief Дружественная функция: сравнивает возраст двух животных
 */
bool isOlder(const Animal& a, const Animal& b) {
    return a.age > b.age;
}
 
/**
 * @brief Указатель на самое старое животное в массиве
 */
Animal* Animal::getOldestAnimal(Animal* animals[], int n) {
    if (n == 0) {
        return nullptr;
    }
    Animal* oldest = animals[0];
    for (int i = 1; i < n; i++) {
        if (isOlder(*animals[i], *oldest)) {
            oldest = animals[i];
        }
    }
    return oldest;
}