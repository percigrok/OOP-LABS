#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include <stdexcept>

/**
 * @class Book
 * @brief Класс для представления книги в библиотеке
 * 
 * Моделирует книгу с информацией о названии, авторе, количестве страниц
 * и статусе выдачи. Обеспечивает операции выдачи и возврата книги
 * с проверкой корректности состояния.
 * 
 * @details
 * Инварианты класса:
 * 1. Количество страниц должно быть положительным (pageCount > 0)
 * 2. Уже выданную книгу нельзя выдать повторно
 * 3. Книгу, которая не была выдана, нельзя вернуть
 */
class Book {
private:
    /**
     * @class PageCount
     * @brief Вложенный класс для представления количества страниц
     * 
     * Инкапсулирует валидацию: количество страниц должно быть положительным
     */
    class PageCount {
    private:
        int value;  ///< Количество страниц (должно быть > 0)

    public:
        /**
         * @brief Конструктор по умолчанию
         * Инициализирует значение 100 страницами
         */
        PageCount() : value(100) {}

        /**
         * @brief Параметризованный конструктор
         * @param pages Количество страниц (должно быть > 0)
         * @throws std::invalid_argument если pages <= 0
         */
        PageCount(int pages) {
            if (pages <= 0) {
                throw std::invalid_argument("Количество страниц должно быть положительным!");
            }
            value = pages;
        }

        /**
         * @brief Получить количество страниц
         * @return Количество страниц
         */
        int getValue() const {
            return value;
        }

        /**
         * @brief Изменить количество страниц
         * @param newValue Новое количество (должно быть > 0)
         * @return true если успешно, false если некорректное значение
         */
        bool setValue(int newValue) {
            if (newValue <= 0) {
                return false;
            }
            value = newValue;
            return true;
        }

        /**
         * @brief Вывести информацию о количестве страниц
         */
        void print() const {
            std::cout << value << " стр.";
        }
    };

    std::string title;              ///< Название книги
    std::string author;             ///< Имя автора
    PageCount pageCount;            ///< Количество страниц
    bool isBorrowed;                ///< Статус выдачи (true = выдана, false = в библиотеке)
    static int totalBooks;          ///< Счётчик всех созданных объектов класса

public:
    /**
     * @brief Конструктор по умолчанию
     * 
     * Создаёт объект книги с корректным начальным состоянием.
     * Инициализирует пустые значения для названия и автора,
     * количество страниц = 100, статус = не выдана.
     */
    Book();

    /**
     * @brief Параметризованный конструктор
     * 
     * Создаёт объект книги со всеми параметрами.
     * 
     * @param title Название книги
     * @param author Автор книги
     * @param pageCount Количество страниц (должно быть > 0)
     * 
     * @throws std::invalid_argument если pageCount <= 0
     * 
     * @details Инвариант: количество страниц должно быть положительным
     */
    Book(const std::string& title, const std::string& author, int pageCount);

    /**
     * @brief Параметризованный конструктор со списком инициализации
     * 
     * Альтернативный способ создания книги с явным указанием статуса.
     * 
     * @param title Название книги
     * @param author Автор книги
     * @param pageCount Количество страниц (должно быть > 0)
     * @param isBorrowed Начальный статус выдачи
     * 
     * @throws std::invalid_argument если pageCount <= 0
     * 
     * @details Инвариант: количество страниц должно быть положительным
     */
    Book(const std::string& title, const std::string& author, int pageCount, bool isBorrowed);

    /**
     * @brief Деструктор класса
     * 
     * Демонстрирует понимание момента завершения времени жизни объекта.
     * На данном этапе не освобождает динамическую память.
     */
    ~Book();

    /**
     * @brief Выдать книгу
     * 
     * Изменяет статус книги на "выдана".
     * 
     * @return true если книга успешно выдана
     * @return false если книга уже была выдана
     * 
     * @details Инвариант: нельзя выдать книгу, которая уже выдана
     */
    bool borrowBook();

    /**
     * @brief Вернуть книгу
     * 
     * Изменяет статус книги на "не выдана".
     * 
     * @return true если книга успешно возвращена
     * @return false если книга не была выдана (нечего возвращать)
     * 
     * @details Инвариант: нельзя вернуть книгу, которая не была выдана
     */
    bool returnBook();

    /**
     * @brief Изменить количество страниц в книге
     * 
     * @param newPageCount Новое количество страниц (должно быть > 0)
     * @return true если страницы успешно обновлены
     * @return false если newPageCount некорректен (<=0)
     * 
     * @details Инвариант: количество страниц должно быть положительным
     */
    bool updatePageCount(int newPageCount);

    /**
     * @brief Получить название книги
     * 
     * @return const std::string& Название книги
     */
    const std::string& getTitle() const;

    /**
     * @brief Получить количество страниц
     * 
     * @return int Количество страниц
     */
    int getPageCount() const;

    /**
     * @brief Вывести информацию о книге
     * 
     * Выводит полную информацию о книге в формате:
     * Название: ...
     * Автор: ...
     * Страниц: ...
     * Статус: ...
     */
    void print() const;

    /**
     * @brief Получить количество существующих объектов
     * 
     * @return int Общее количество созданных книг
     */
    static int getTotalBooks();
};

#endif 
