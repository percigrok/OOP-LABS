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

/**
 * @brief Перевод даты в номер дня от 01.01.1900
 */
int Date::toSerial() const {
    int s = 0;
    for (int y = 1900; y < year; ++y) {
        s += isLeap(y) ? 366 : 365;
    }
    for (int m = 1; m < month; ++m) {
        s += daysInMonth(m, year);
    }
    return s + day - 1;
}
 
/**
 * @brief Установка day, month, year по номеру дня
 */
void Date::assignSerial(int serial) {
    int y = 1900;
    while (serial >= (isLeap(y) ? 366 : 365)) {
        serial -= isLeap(y) ? 366 : 365;
        ++y;
    }
    int m = 1;
    while (serial >= daysInMonth(m, y)) {
        serial -= daysInMonth(m, y);
        ++m;
    }
    year = y;
    month = m;
    day = serial + 1;
}

/**
 * @brief Конструктор по умолчанию
 */
Date::Date() : day(1), month(1), year(2000), accessCount(0) {
    ++objectCount;
}
 
/**
 * @brief Параметризованный конструктор
 */
Date::Date(int d, int m, int y) : day(d), month(m), year(y), accessCount(0) {
    if (y < 1900) {
        throw std::invalid_argument("Год должен быть не раньше 1900");
    }
    if (m < 1 || m > 12) {
        throw std::invalid_argument("Месяц должен быть от 1 до 12");
    }
    if (d < 1 || d > daysInMonth(m, y)) {
        throw std::invalid_argument("Некорректный день месяца");
    }
    ++objectCount;
}

/**
 * @brief Явный конструктор из номера дня
 */
Date::Date(int serial) : day(1), month(1), year(1900), accessCount(0) {
    if (serial < 0) {
        throw std::invalid_argument("Номер дня не может быть отрицательным");
    }
    assignSerial(serial);
    ++objectCount;
}
 
/**
 * @brief Копирующий конструктор
 */
Date::Date(const Date& other)
    : day(other.day), month(other.month), year(other.year), accessCount(other.accessCount) {
    ++objectCount;
}

/**
 * @brief Оператор присваивания (счётчик объектов не меняется)
 */
Date& Date::operator=(const Date& other) {
    day = other.day;
    month = other.month;
    year = other.year;
    accessCount = other.accessCount;
    return *this;
}
 
/**
 * @brief Деструктор
 */
Date::~Date() {
    --objectCount;
}