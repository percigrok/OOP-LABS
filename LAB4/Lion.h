#ifndef LION_H
#define LION_H

#include "Mammal.h"

/**
 * @class Lion
 * @brief Лев
 */
class LAB3_API Lion : public Mammal {
public:
    Lion(const char* name, int age, int gestationDays);
    const char* makeSound() const override;
    const char* getSpecies() const override;
    void move() const override;   ///< Переопределяет Animal::move
};

#endif // LION_H