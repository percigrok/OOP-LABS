#include <iostream>
 
/**
 * @brief Выделяет память для двумерного целочисленного массива (матрицы)
 * @param rows Количество строк
 * @param cols Количество столбцов
 * @return Указатель на массив указателей (указатель на матрицу)
 * @details
 * - Выделяет массив из 'rows' указателей
 * - Для каждого указателя выделяет массив из 'cols' целых чисел
 * - Все элементы инициализируются нулем через {}
 */
int** allocateMatrix(int rows, int cols)
{
    int** matrix = new int*[rows]{};
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols]{};
    }
    return matrix;
}

/**
 * @brief Заполняет матрицу значениями со стандартного ввода
 * @param matrix Указатель на матрицу (указатель на массив указателей)
 * @param rows Количество строк
 * @param cols Количество столбцов
 * @details Читает rows*cols значений в порядке по строкам
 */
void fillMatrix(int** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
}

/**
 * @brief Выводит матрицу с опциональным форматированием
 * @param matrix Указатель на матрицу
 * @param rows Количество строк
 * @param cols Количество столбцов
 * @param showBorders Выводить вертикальные границы (по умолчанию: true)
 * @param title Заголовок матрицы (по умолчанию: "Matrix")
 * @details
 * - Использует параметры по умолчанию для гибкого вызова функции
 * - showBorders = true: добавляет разделители "|"
 * - showBorders = false: простой вывод без границ
 * - Выводит заголовок перед содержимым матрицы
 */
void printMatrix(int** matrix, int rows, int cols, bool showBorders = true, const char* title = "Matrix")
{
    std::cout << title << std::endl;
 
    for (int i = 0; i < rows; i++)
    {
        if (showBorders)
        {
            std::cout << "| ";
        }
        for (int j = 0; j < cols; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        if (showBorders)
        {
            std::cout << "|";
        }
        std::cout << std::endl;
    }
}