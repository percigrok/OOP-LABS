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