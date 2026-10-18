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