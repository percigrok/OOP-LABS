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

/**
 * @brief Безопасный доступ к элементу массива с проверкой границ
 * @param arr Ссылка на структуру SafeArray
 * @param index Индекс элемента
 * @return Ссылка на элемент массива или статическую переменную если индекс вне границ
 * @details
 * - Проверяет находится ли индекс в допустимом диапазоне [0, size)
 * - Если индекс некорректный: выводит "Error" и возвращает ссылку на статическую переменную
 * - Если индекс корректный: возвращает ссылку на arr.data[index]
 * - Может быть использована слева от оператора присваивания: getElement(arr, 0) = 5;
 */
int& getElement(SafeArray& arr, int index)
{
    static int error = -1;
    if (index >= arr.size || index < 0)
    {
        std::cout << "Error";
        return error;
    }
    return arr.data[index];
}

/**
 * @brief Выводит содержимое массива на экран
 * @param arr Констатная ссылка на структуру SafeArray
 * @details Использует const чтобы указать что массив не изменяется во время вывода
 */
void printSafe(const SafeArray& arr)
{
    for (int i = 0; i < arr.size; i++)
    {
        std::cout << arr.data[i] << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Изменяет размер массива на новый размер
 * @param arr Ссылка на структуру SafeArray
 * @param newSize Новый размер массива
 * @details
 * - Если newSize < текущий размер: выводит удаленные элементы перед обрезкой
 * - Если newSize > текущий размер: новые элементы инициализируются нулем
 * - Сохраняет существующие элементы до минимума из старого и нового размера
 * - Безопасно освобождает старую память перед обновлением указателя
 */
void reSizeArray(SafeArray& arr, int newSize)
{
    if (newSize < arr.size)
    {
        for (int i = newSize; i < arr.size; i++)
        {
            std::cout << arr.data[i] << " ";
        }
        std::cout << std::endl;
    }
 
    int* newData = new int[newSize]{};
 
    int copySize = (newSize < arr.size) ? newSize : arr.size;
    for (int i = 0; i < copySize; i++)
    {
        newData[i] = arr.data[i];
    }
 
    delete[] arr.data;
    arr.data = newData;
    arr.size = newSize;
}

