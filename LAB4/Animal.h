#ifndef ANIMAL_H
#define ANIMAL_H
 
#include "lab3_export.h"
 
/**
 * @class Animal
 * @brief Абстрактное животное, корень иерархии
 */
class LAB3_API Animal {
protected:
    char* name;                          ///< Имя (динамическая строка)
    int age;                             ///< Возраст в годах
 
    void setName(const char* newName);   ///< Копирует имя в новую память