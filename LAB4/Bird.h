#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"

/**
 * @class Bird
 * @brief Птица (промежуточный класс, абстрактный)
 */
class LAB3_API Bird : public virtual Animal {
protected:
    double wingspan;   ///< Размах крыльев, см
    bool canFly;       ///< Умеет ли летать

public:
    Bird(const char* name, int age, double wingspan, bool canFly);
    Bird(const Bird& other);
    Bird& operator=(const Bird& other);

    double getWingspan() const;
    bool getCanFly() const;
};

#endif // BIRD_H