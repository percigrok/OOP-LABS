#include "Book.h"

// Инициализация статического члена класса
int Book::totalBooks = 0;

/**
 * @brief Конструктор по умолчанию
 */
Book::Book() : title(""), author(""), pageCount(), isBorrowed(false) {
    totalBooks++;
}

/**
 * @brief Параметризованный конструктор
 */
Book::Book(const std::string& title, const std::string& author, int pageCount)
    : title(title), author(author), pageCount(pageCount), isBorrowed(false) {
    
    totalBooks++;
}

/**
 * @brief Параметризованный конструктор со списком инициализации
 */
Book::Book(const std::string& title, const std::string& author, int pageCount, bool isBorrowed)
    : title(title), author(author), pageCount(pageCount), isBorrowed(isBorrowed) {
    
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
    // Инвариант: уже выданную книгу нельзя выдать повторно
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
    // Инвариант: книгу, которая не была выдана, нельзя вернуть
    if (!isBorrowed) {
        return false;  // Книга не была выдана
    }
    isBorrowed = false;
    return true;  // Успешно возвращена
}

/**
 * @brief Изменить количество страниц
 */
bool Book::updatePageCount(int newPageCount) {
    return pageCount.setValue(newPageCount);
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
    return pageCount.getValue();
}

/**
 * @brief Вывести информацию о книге
 */
void Book::print() const {
    std::cout << "===== Информация о книге =====\n";
    std::cout << "Название: " << title << "\n";
    std::cout << "Автор: " << author << "\n";
    std::cout << "Количество страниц: ";
    pageCount.print();
    std::cout << "\n";
    std::cout << "Статус: ";
    if (isBorrowed) {
        std::cout << "ВЫДАНА\n";
    } else {
        std::cout << "В БИБЛИОТЕКЕ\n";
    }
    std::cout << "============================\n";
}

/**
 * @brief Получить количество объектов
 */
int Book::getTotalBooks() {
    return totalBooks;
}