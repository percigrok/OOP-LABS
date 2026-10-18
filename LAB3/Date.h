#ifndef DATE_H
#define DATE_H
 
#include <string>
#include <iostream>
#include <stdexcept>
 
/**
 * @class Date
 * @brief Дата (день, месяц, год) с перегрузкой операторов
 *
 * @details Для сравнения и арифметики дата переводится в номер дня:
 * сколько дней прошло с 01.01.1900 (этот день имеет номер 0).
 */
class Date {
private:
    int day;                    ///< День месяца (1..31)
    int month;                  ///< Месяц (1..12)
    int year;                   ///< Год (не раньше 1900)
    mutable int accessCount;    ///< Количество обращений к дате (mutable: меняется даже у const объекта)
    static int objectCount;     ///< Статический счётчик живых объектов Date
 
    static bool isLeap(int y);              ///< Високосный ли год
    static int daysInMonth(int m, int y);   ///< Сколько дней в месяце
    int toSerial() const;                   ///< Номер дня от 01.01.1900
    void assignSerial(int serial);          ///< Установить день, месяц и год по номеру дня
    
    public:
    /**
     * @brief Конструктор по умолчанию
     * Создаёт дату 01.01.2000
     */
    Date();

    /**
     * @brief Параметризованный конструктор
     * @param d День
     * @param m Месяц
     * @param y Год
     * @throws std::invalid_argument если дата некорректна
     */
    Date(int d, int m, int y);
 
    /**
     * @brief Явный конструктор из номера дня
     * @param serial Количество дней с 01.01.1900
     * @details explicit запрещает неявное преобразование int -> Date
     * @throws std::invalid_argument если serial < 0
     */
    explicit Date(int serial);

     /**
     * @brief Копирующий конструктор
     * @param other Копируемая дата
     */
    Date(const Date& other);
    /** @brief Оператор присваивания (счётчик объектов не меняется) */
    Date& operator=(const Date& other);
 
    /**
     * @brief Деструктор
     * Уменьшает статический счётчик живых объектов
     */
    ~Date();

     /** @brief Префиксный инкремент: переход на следующий день */
    Date& operator++();
 
    /** @brief Постфиксный инкремент: возвращает старую дату */
    Date operator++(int);
 
    /** @brief Префиксный декремент: переход на предыдущий день */
    Date& operator--();
 
    /** @brief Постфиксный декремент: возвращает старую дату */
    Date operator--(int);

     /**
     * @brief Добавить дни
     * @throws std::out_of_range если результат раньше 01.01.1900
     */
    Date& operator+=(int days);
 
    /**
     * @brief Вычесть дни
     * @throws std::out_of_range если результат раньше 01.01.1900
     */
    Date& operator-=(int days);
 
    /**
     * @brief Умножить номер дня на число (демонстрационная операция)
     * @throws std::out_of_range если результат раньше 01.01.1900
     */
    Date& operator*=(int k);
 
    /**
     * @brief Разделить номер дня на число (демонстрационная операция)
     * @throws std::invalid_argument если k == 0
     */
    Date& operator/=(int k);

    /** @brief Дата + дни (через +=) */
    friend Date operator+(Date lhs, int days) { lhs += days; return lhs; }
 
    /** @brief Дата - дни (через -=) */
    friend Date operator-(Date lhs, int days) { lhs -= days; return lhs; }
 
    /** @brief Дата * число (через *=) */
    friend Date operator*(Date lhs, int k) { lhs *= k; return lhs; }
 
    /** @brief Дата / число (через /=) */
    friend Date operator/(Date lhs, int k) { lhs /= k; return lhs; }
 
    /** @brief Разность дат в днях (lhs - rhs) */
    friend int operator-(const Date& lhs, const Date& rhs) { return lhs.toSerial() - rhs.toSerial(); }

    /** @brief Равны ли даты */
    friend bool operator==(const Date& a, const Date& b) { return a.toSerial() == b.toSerial(); }
 
    /** @brief Не равны ли даты */
    friend bool operator!=(const Date& a, const Date& b) { return !(a == b); }
 
    /** @brief Раньше ли a, чем b */
    friend bool operator<(const Date& a, const Date& b) { return a.toSerial() < b.toSerial(); }
 
    /** @brief Позже ли a, чем b */
    friend bool operator>(const Date& a, const Date& b) { return b < a; }
 
    /** @brief a не позже b */
    friend bool operator<=(const Date& a, const Date& b) { return !(b < a); }
 
    /** @brief a не раньше b */
    friend bool operator>=(const Date& a, const Date& b) { return !(a < b); }