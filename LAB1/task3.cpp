#include <iostream>
 
/**
 * @struct SafeArray
 * @brief Структура для безопасного управления массивом
 */
struct SafeArray {
    int* data;      ///< Указатель на динамически выделяемый массив
    int size;       ///< Количество элементов в массиве
};