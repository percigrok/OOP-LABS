#include <iostream>
 
/**
 * @brief Обрабатывает динамический массив, обрезая его на первом отрицательном элементе
 * @param arr Ссылка на указатель на динамический массив
 * @param size Ссылка на размер массива
 * @details
 * - Ищет первый отрицательный элемент в массиве
 * - Если найден: создает новый массив содержащий только элементы до отрицательного
 * - Освобождает старый массив и обновляет указатель на новый
 * - Обновляет размер массива согласно новой длине
 * @note Использует ссылку на указатель (int*&) чтобы иметь возможность изменить сам указатель
 */
void process(int*& arr, int& size)
{
    int negativeIndex = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            negativeIndex = i;
            break;
        }
    }
 
    if (negativeIndex != -1)
    {
        int newSize = negativeIndex;
        int* newArr = new int[newSize]{};
 
        for (int i = 0; i < newSize; i++)
        {
            newArr[i] = arr[i];
        }
 
        delete[] arr;
        arr = nullptr;
 
        arr = newArr;
        size = newSize;
    }
}
/**
 * @brief Главная функция программы
 * @details
 * 1. Читает размер массива N с клавиатуры
 * 2. Выделяет память для N целых чисел
 * 3. Читает N значений со стандартного ввода
 * 4. Выводит исходный массив
 * 5. Обрабатывает массив (обрезает на первом отрицательном элементе)
 * 6. Выводит результирующий массив
 * 7. Безопасно освобождает память
 */
int main()
{
    int n;
    std::cin >> n;
 
    int* arr = new int[n]{};
 
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
 
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
 
    process(arr, n);
 
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
 
    delete[] arr;
    arr = nullptr;
 
    return 0;
}