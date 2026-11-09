#ifndef ZOO_CLIENT_H
#define ZOO_CLIENT_H

class Animal;

/**
 * @brief Загрузить животных из файла
 * @return Количество загруженных животных
 */
int loadZoo(const char* fileName, Animal* zoo[]);

/**
 * @brief Запустить все проверки
 */
void runTests(const char* fileName);

#endif // ZOO_CLIENT_H