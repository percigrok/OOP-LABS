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