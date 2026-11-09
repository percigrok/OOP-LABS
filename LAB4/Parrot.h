#ifndef PARROT_H
#define PARROT_H

#include "Bird.h"

/**
 * @class Parrot
 * @brief Попугай
 */
class LAB3_API Parrot : public Bird {
public:
    Parrot(const char* name, int age, double wingspan, bool canFly);
    const char* makeSound() const override;
    const char* getSpecies() const override;
    void move() const override;   ///< Переопределяет Animal::move
};

#endif // PARROT_H