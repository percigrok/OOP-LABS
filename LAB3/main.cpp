#include <clocale>
#include <iostream>
#include <string>
#include <type_traits>
#include "Date.h"
#include "Schedule.h"
 
/**
 * @brief Вывести дату с названием и днём недели
 * @param name Название для вывода
 * @param d Дата
 */
static void show(const std::string& name, const Date& d) {
    std::cout << name << " = ";
    d.print();
    std::cout << " (" << d.getWeekday() << ")\n";
}
 
/**
 * @brief Главная функция - демонстрация класса Date и расписания
 */
int main() {
    setlocale(LC_ALL, ".UTF-8");
    auto yn = [](bool b) { return b ? "да" : "нет"; };