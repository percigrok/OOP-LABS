#ifndef DATE_H
#define DATE_H

#include <string>

/**
 * @class Date
 * @brief Дата: день, месяц, год
 */
class Date {
private:
    int day;                  ///< День месяца
    int month;                ///< Месяц
    int year;                 ///< Год
    mutable int readCount;    ///< Сколько раз читали дату (mutable)
    static int objectCount;   ///< Сколько объектов Date существует сейчас

    static bool isLeap(int y);
    static int daysInMonth(int m, int y);
    int toSerial() const;               ///< Номер дня от 01.01.1900
    void setFromSerial(int serial);     ///< Дата по номеру дня

public:
    Date();                        ///< Дата 01.01.2000
    Date(int d, int m, int y);     ///< Дата с проверкой
    explicit Date(int serial);     ///< Дата по номеру дня (explicit)
    Date(const Date& other);       ///< Копирующий конструктор
    ~Date();                       ///< Деструктор

    Date& operator=(const Date& other);

    Date& operator++();
    Date operator++(int);
    Date& operator--();
    Date operator--(int);

    Date& operator+=(int days);
    Date& operator-=(int days);
    Date& operator*=(int k);
    Date& operator/=(int k);

    friend Date operator+(Date d, int days) { d += days; return d; }
    friend Date operator-(Date d, int days) { d -= days; return d; }
    friend Date operator*(Date d, int k) { d *= k; return d; }
    friend Date operator/(Date d, int k) { d /= k; return d; }
    friend int operator-(const Date& a, const Date& b) { return a.toSerial() - b.toSerial(); }

    friend bool operator==(const Date& a, const Date& b) { return a.toSerial() == b.toSerial(); }
    friend bool operator!=(const Date& a, const Date& b) { return !(a == b); }
    friend bool operator<(const Date& a, const Date& b) { return a.toSerial() < b.toSerial(); }
    friend bool operator>(const Date& a, const Date& b) { return b < a; }
    friend bool operator<=(const Date& a, const Date& b) { return !(b < a); }
    friend bool operator>=(const Date& a, const Date& b) { return !(a < b); }

    int getDay() const;
    int getMonth() const;
    int getYear() const;
    int getReadCount() const;
    std::string getWeekday() const;
    void print() const;
    static int getObjectCount();
};

#endif // DATE_H