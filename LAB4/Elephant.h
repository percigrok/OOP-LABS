#ifndef ELEPHANT_H
#define ELEPHANT_H

#include "Mammal.h"

/**
 * @class Elephant
 * @brief Слон
 */
class LAB3_API Elephant : public Mammal {
public:
    Elephant(const char* name, int age, int gestationDays);
    const char* makeSound() const override;
    const char* getSpecies() const override;
};

#endif // ELEPHANT_H