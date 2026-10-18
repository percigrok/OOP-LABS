#include "Schedule.h"

/**
 * @brief Добавить мероприятие
 */
void Schedule::addEvent(const std::string& name, const Date& date) {
    events.push_back(Event{name, date});
}

/**
 * @brief Количество мероприятий в месяце
 */
int Schedule::countInMonth(int month, int year) const {
    int count = 0;
    for (const Event& e : events) {
        if (e.date.getMonth() == month && e.date.getYear() == year) {
            ++count;
        }
    }
    return count;
}

/**
 * @brief Количество мероприятий в году
 */
int Schedule::countInYear(int year) const {
    int count = 0;
    for (const Event& e : events) {
        if (e.date.getYear() == year) {
            ++count;
        }
    }
    return count;
}

/**
 * @brief Размер расписания
 */
std::size_t Schedule::size() const {
    return events.size();
}

/**
 * @brief Вывод расписания
 */
void Schedule::print() const {
    for (std::size_t i = 0; i < events.size(); ++i) {
        std::cout << (i + 1) << ". " << events[i].name << " - ";
        events[i].date.print();
        std::cout << " (" << events[i].date.getWeekday() << ")\n";
    }
}