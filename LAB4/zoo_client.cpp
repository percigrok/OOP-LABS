/**
 * Клиентский код. Классы Animal, Mammal и Bird абстрактные:
 * у них не реализованы makeSound() и getSpecies(), поэтому объекты
 * этих классов не создаются. Объекты создаются только у Lion, Elephant,
 * Parrot и Bat (по 3 штуки в zoo.txt).
 */
#include "zoo_client.h"

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

#include "Animal.h"
#include "Bat.h"
#include "Elephant.h"
#include "Lion.h"
#include "Parrot.h"

const int MAX_ANIMALS = 20;

/**
 * @brief Читает животных из файла
 */
int loadZoo(const char* fileName, Animal* zoo[]) {
    std::ifstream in(fileName);
    if (!in) {
        std::cout << "Не удалось открыть файл " << fileName << "\n";
        return 0;
    }

    int n = 0;
    std::string type, name;
    int age;
    while (n < MAX_ANIMALS && in >> type >> name >> age) {
        if (type == "Lion") {
            int gestation;
            in >> gestation;
            zoo[n++] = new Lion(name.c_str(), age, gestation);
        } else if (type == "Elephant") {
            int gestation;
            in >> gestation;
            zoo[n++] = new Elephant(name.c_str(), age, gestation);
        } else if (type == "Parrot") {
            double wingspan;
            int canFly;
            in >> wingspan >> canFly;
            zoo[n++] = new Parrot(name.c_str(), age, wingspan, canFly != 0);
        } else if (type == "Bat") {
            int gestation;
            double wingspan;
            in >> gestation >> wingspan;
            zoo[n++] = new Bat(name.c_str(), age, gestation, wingspan);
        }
    }
    return n;
}

/**
 * @brief Все проверки: полиморфизм, статика, копирование, удаление
 */
void runTests(const char* fileName) {
    Animal* zoo[MAX_ANIMALS];
    int n = loadZoo(fileName, zoo);
    std::cout << "=== Загружено животных: " << n << " ===\n";
    std::cout << "Живых объектов Animal (static): " << Animal::getTotalCount() << "\n\n";

    std::cout << "=== Полиморфный вызов ===\n";
    for (int i = 0; i < n; i++) {
        std::cout << zoo[i]->getName() << " (" << zoo[i]->getSpecies() << ", "
                  << zoo[i]->getAge() << " лет), звук: " << zoo[i]->makeSound() << "\n";
        zoo[i]->move();
    }

    std::cout << "\n=== Статистика по видам ===\n";
    const char* kinds[] = {"Лев", "Слон", "Попугай", "Летучая мышь"};
    for (const char* kind : kinds) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (std::strcmp(zoo[i]->getSpecies(), kind) == 0) {
                count++;
            }
        }
        std::cout << kind << ": " << count << "\n";
    }

    std::cout << "\n=== Самое старое животное ===\n";
    Animal* oldest = Animal::getOldestAnimal(zoo, n);
    std::cout << oldest->getName() << ", " << oldest->getAge() << " лет\n\n";

    std::cout << "=== Копирование и присваивание (Bat) ===\n";
    Bat original("Batty", 3, 45, 25.0);
    Bat copy(original);
    Bat assigned("Other", 1, 10, 10.0);
    assigned = original;
    std::cout << "copy: " << copy.getName() << ", assigned: " << assigned.getName() << "\n";
    std::cout << "Имена хранятся в разной памяти: "
              << (original.getName() != copy.getName() ? "да" : "нет") << "\n";
    original = Bat("Новый", 9, 50, 30.0);
    std::cout << "После original = Bat(\"Новый\"): original " << original.getName()
              << ", copy " << copy.getName() << "\n";
    std::cout << "Живых объектов Animal сейчас: " << Animal::getTotalCount() << "\n\n";

    for (int i = 0; i < n; i++) {
        delete zoo[i];
    }
    std::cout << "После удаления зоопарка: " << Animal::getTotalCount() << "\n";
}