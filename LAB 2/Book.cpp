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