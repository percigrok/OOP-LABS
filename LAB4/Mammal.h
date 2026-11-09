#ifndef MAMMAL_H
#define MAMMAL_H

#include "Animal.h"

/**
 * @class Mammal
 * @brief Млекопитающее (промежуточный класс, абстрактный)
 */
class LAB3_API Mammal : public virtual Animal {
protected:
    int gestationDays;   ///< Срок беременности, дней
    bool nursing;        ///< Кормит ли детёнышей молоком

public:
    Mammal(const char* name, int age, int gestationDays);
    Mammal(const Mammal& other);
    Mammal& operator=(const Mammal& other);

    int getGestationDays() const;
    bool isNursing() const;
};

#endif // MAMMAL_H