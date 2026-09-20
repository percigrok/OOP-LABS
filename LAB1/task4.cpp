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