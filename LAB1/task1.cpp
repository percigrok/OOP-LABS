#include <iostream>

/// Заполняет массив данными с клавиатуры
/// @param arr Ссылка на массив из 10 целых чисел
/// @details Читает 10 значений со стандартного ввода и сохраняет их в массив
void fillArray(int (&arr)[10])
{
    for (int i = 0; i < 10; i++)
    {
        std::cin >> arr[i];
    }
}

/// Выводит элементы массива на экран
/// @param arr Ссылка на массив из 10 целых чисел
/// @details Использует range-based for цикл с ключевым словом auto для вывода всех элементов
void printArray(int (&arr)[10])
{
    for (auto x : arr)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

/// Обменивает два элемента массива по индексам
/// @param arr Ссылка на массив из 10 целых чисел
/// @param index1 Индекс первого элемента
/// @param index2 Индекс второго элемента
/// @details Обменивает значения элементов на указанных позициях
void swapElements(int (&arr)[10], int index1, int index2)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}
