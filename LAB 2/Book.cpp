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