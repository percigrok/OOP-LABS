#include "Book.h"
#include <stdexcept>
 
// Инициализация статического члена класса
int Book::totalBooks = 0;
 
/**
 * @brief Конструктор по умолчанию
 */
Book::Book() : title(""), author(""), pageCount(100), isBorrowed(false) {
    totalBooks++;
}

/**
 * @brief Параметризованный конструктор
 */
Book::Book(const std::string& title, const std::string& author, int pageCount)
    : title(title), author(author), pageCount(pageCount), isBorrowed(false) {
    
    // Инвариант 1: количество страниц должно быть положительным
    if (pageCount <= 0) {
        throw std::invalid_argument("Количество страниц должно быть положительным!");
    }
    totalBooks++;
}

/**
 * @brief Параметризованный конструктор со списком инициализации
 */
Book::Book(const std::string& title, const std::string& author, int pageCount, bool isBorrowed)
    : title(title), author(author), pageCount(pageCount), isBorrowed(isBorrowed) {
    
    // Инвариант 1: количество страниц должно быть положительным
    if (pageCount <= 0) {
        throw std::invalid_argument("Количество страниц должно быть положительным!");
    }
    totalBooks++;
}

/**
 * @brief Деструктор класса
 */
Book::~Book() {
    totalBooks--;
}

/**
 * @brief Выдать книгу
 */
bool Book::borrowBook() {
    // Инвариант 2: уже выданную книгу нельзя выдать повторно
    if (isBorrowed) {
        return false;  // Книга уже выдана
    }
    isBorrowed = true;
    return true;  // Успешно выдана
}

/**
 * @brief Вернуть книгу
 */
bool Book::returnBook() {
    // Инвариант 3: книгу, которая не была выдана, нельзя вернуть
    if (!isBorrowed) {
        return false;  // Книга не была выдана
    }
    isBorrowed = false;
    return true;  // Успешно возвращена
}

/**
 * @brief Получить название книги
 */
const std::string& Book::getTitle() const {
    return title;
}
 
/**
 * @brief Получить количество страниц
 */
int Book::getPageCount() const {
    return pageCount;
}