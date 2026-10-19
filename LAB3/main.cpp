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

     std::cout << "===== КЛАСС DATE =====\n\n";
 
    // Конструкторы
    std::cout << "--- Конструкторы ---\n";
    Date d1;               // конструктор по умолчанию
    Date d2(15, 3, 2024);  // параметризованный конструктор
    Date d3(d2);           // копирующий конструктор
    Date d4(0);            // explicit конструктор (номер дня 0 = 01.01.1900)
    show("d1", d1);
    show("d2", d2);
    show("d3", d3);
    show("d4", d4);
    std::cout << "\n";
 
    // Унарные операторы
    std::cout << "--- Унарные операторы ---\n";
    ++d1;
    show("после ++d1", d1);
    Date old = d1++;
    show("old = d1++ (старое)", old);
    show("d1 (новое)", d1);
    --d1;
    show("после --d1", d1);
    old = d1--;
    show("old = d1-- (старое)", old);
    show("d1 (новое)", d1);
    std::cout << "\n";
 
    // Составные операторы
    std::cout << "--- Составные операторы ---\n";
    d2 += 10;
    show("d2 += 10", d2);
    d2 -= 3;
    show("d2 -= 3", d2);
    Date d5(10);  // 11.01.1900
    d5 *= 2;
    show("d5 *= 2", d5);
    d5 /= 4;
    show("d5 /= 4", d5);
    std::cout << "\n";
 
    // Бинарные операторы
    std::cout << "--- Бинарные операторы ---\n";
    show("d2 + 30", d2 + 30);
    show("d2 - 5", d2 - 5);
    std::cout << "Разность d1 - d2 = " << (d1 - d2) << " дн.\n";
    show("d5 * 3", d5 * 3);
    std::cout << "\n";
 
    // Операторы сравнения
    std::cout << "--- Сравнение ---\n";
    std::cout << "d2 == d3: " << yn(d2 == d3) << "\n";
    std::cout << "d2 != d1: " << yn(d2 != d1) << "\n";
    std::cout << "d1 < d2:  " << yn(d1 < d2) << "\n";
    std::cout << "d1 > d2:  " << yn(d1 > d2) << "\n";
    std::cout << "d1 <= d2: " << yn(d1 <= d2) << "\n";
    std::cout << "d2 >= d3: " << yn(d2 >= d3) << "\n\n";

    // explicit
    std::cout << "--- explicit ---\n";
    std::cout << "Неявное преобразование int -> Date возможно: "
              << yn(std::is_convertible<int, Date>::value) << "\n";
    std::cout << "Явное создание Date из int возможно: "
              << yn(std::is_constructible<Date, int>::value) << "\n";
    // Date bad = 100;   // ОШИБКА компиляции: explicit запрещает неявное преобразование
    Date ok(100);        // явное преобразование работает
    show("Date ok(100)", ok);
    std::cout << "\n";
 
    // mutable и const
    std::cout << "--- mutable и const ---\n";
    const Date holiday(31, 12, 2025);  // const объект
    holiday.getDay();
    holiday.getMonth();
    std::cout << "const holiday прочитан 2 раза, счётчик: " << holiday.getAccessCount() << "\n";
    holiday.print();
    std::cout << "\nПосле print() счётчик: " << holiday.getAccessCount() << "\n\n";

    // static и деструктор
    std::cout << "--- static и деструктор ---\n";
    std::cout << "Объектов до блока: " << Date::getObjectCount() << "\n";
    {
        Date temp(1, 1, 2030);
        std::cout << "Внутри блока: " << Date::getObjectCount() << "\n";
    }
    std::cout << "После блока (вызвался деструктор): " << Date::getObjectCount() << "\n\n";
 
    // Расписание
    std::cout << "--- Расписание мероприятий ---\n";
    Schedule plan;
    plan.addEvent("Сдача лабы по ООП", Date(20, 10, 2026));
    plan.addEvent("Защита курсовой", Date(25, 10, 2026));
    plan.addEvent("День рождения", Date(5, 11, 2026));
    plan.addEvent("Новогодняя вечеринка", Date(31, 12, 2026));
    plan.addEvent("Экзамен", Date(10, 1, 2027));
    plan.print();
    std::cout << "\nВсего мероприятий: " << plan.size() << "\n";
    std::cout << "В октябре 2026: " << plan.countInMonth(10, 2026) << "\n";
    std::cout << "В 2026 году: " << plan.countInYear(2026) << "\n";
    std::cout << "В 2027 году: " << plan.countInYear(2027) << "\n\n";
 
    std::cout << "===== КОНЕЦ =====\n";
    return 0;
}