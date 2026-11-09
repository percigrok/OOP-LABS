#ifndef BAT_H
#define BAT_H

#include "Mammal.h"
#include "Bird.h"

/**
 * @class Bat
 * @brief Летучая мышь: млекопитающее и летающее существо (множественное наследование)
 */
class LAB3_API Bat : public Mammal, public Bird {
public:
    Bat(const char* name, int age, int gestationDays, double wingspan);
    Bat(const Bat& other);
    Bat& operator=(const Bat& other);

    const char* makeSound() const override;
    const char* getSpecies() const override;
};

#endif // BAT_H