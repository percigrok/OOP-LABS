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