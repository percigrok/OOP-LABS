#ifndef SCHEDULE_H
#define SCHEDULE_H
 
#include <string>
#include <vector>
#include <cstddef>
#include "Date.h"
 
/**
 * @class Schedule
 * @brief Расписание мероприятий
 */
class Schedule {
public:
    /**
     * @struct Event
     * @brief Одно мероприятие
     */
    struct Event {
        std::string name;  ///< Название мероприятия
        Date date;         ///< Дата проведения (день недели вычисляется из даты)
    };
 
private:
    std::vector<Event> events;  ///< Список мероприятий
 
public:
    /**
     * @brief Добавить мероприятие
     * @param name Название
     * @param date Дата
     */
     void addEvent(const std::string& name, const Date& date);
 
    /**
     * @brief Сколько мероприятий в заданном месяце года
     */
    int countInMonth(int month, int year) const;
 
    /**
     * @brief Сколько мероприятий в заданном году
     */
    int countInYear(int year) const;

    /**
     * @brief Количество мероприятий в расписании
     */
    std::size_t size() const;
 
    /**
     * @brief Вывести расписание
     */
    void print() const;
};
 
#endif // SCHEDULE_H