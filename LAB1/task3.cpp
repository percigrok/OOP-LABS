#include <iostream>
 
/**
 * @struct SafeArray
 * @brief Структура для безопасного управления массивом
 */
struct SafeArray {
    int* data;      ///< Указатель на динамически выделяемый массив
    int size;       ///< Количество элементов в массиве
};

/**
 * @brief Создает и инициализирует безопасный массив
 * @param size Количество элементов для выделения памяти
 * @return Структура SafeArray с выделенной памятью (элементы инициализированы нулем)
 * @note Возвращает по значению; все элементы инициализированы нулем через {}
 */
SafeArray createArray(int size)
{
    SafeArray arr;
    arr.data = new int[size]{};
    arr.size = size;
    return arr;
}