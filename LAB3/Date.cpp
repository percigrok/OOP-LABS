#include "Date.h"
 
int Date::objectCount = 0;
 
/**
 * @brief Проверка високосного года
 */
bool Date::isLeap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}
 
/**
 * @brief Количество дней в месяце
 */
int Date::daysInMonth(int m, int y) {
    static const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && isLeap(y)) {
        return 29;
    }
    return days[m - 1];
}