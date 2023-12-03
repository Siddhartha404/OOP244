/* Citation and Sources...
Final Project Milestone 1
Module: Date
Filename: Date.cpp
Version 1.0
Author	Siddhartha Thapa Chhetri
Revision History
-----------------------------------------------------------
Date      Reason
2023/?/?  Preliminary release
2023/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#include <iostream>
#include <iomanip>
#include <string>
#include "Date.h"
#include "Utils.h"

namespace sdds {
    Date::Date() : m_year(0), m_month(0), m_day(0), m_formatted(true) {
        ut.getSystemDate(&m_year, &m_month, &m_day);
    }

    Date::Date(int year, int month, int day) : m_year(year), m_month(month), m_day(day), m_formatted(true) {
        if (!validate()) {
            m_state = "Invalid date in date";
        }
    }

    bool Date::validate() {
        int year;
        ut.getSystemDate(&year);
        if (m_year < year || m_year > MAX_YEAR) {
            m_state = "Invalid year in date";
            m_state = 1;
            return false;
        }
        if (m_month < 1 || m_month > 12) {
            m_state = "Invalid month in date";
            m_state = 2;
            return false;
        }
        if (m_day < 1 || m_day > ut.daysOfMon(m_month, m_year)) {
            m_state = "Invalid day in date";
            m_state = 3;
            return false;
        }
        m_state.clear();
        return true;
    }

    void Date::formatted(bool value) {
        m_formatted = value;
    }

    Status Date::state() const {
        return m_state;
    }

    bool Date::operator==(const Date& other) const {
        return uniqueDateValue() == other.uniqueDateValue();
    }

    bool Date::operator!=(const Date& other) const {
        return uniqueDateValue() != other.uniqueDateValue();
    }

    bool Date::operator<(const Date& other) const {
        return uniqueDateValue() < other.uniqueDateValue();
    }

    bool Date::operator>(const Date& other) const {
        return uniqueDateValue() > other.uniqueDateValue();
    }

    bool Date::operator<=(const Date& other) const {
        return uniqueDateValue() <= other.uniqueDateValue();
    }

    bool Date::operator>=(const Date& other) const {
        return uniqueDateValue() >= other.uniqueDateValue();
    }

    int Date::uniqueDateValue() const {
        return m_year * 372 + m_month * 31 + m_day;
    }

    void Date::read(std::istream& is) {
        int year, month, day;
        int currYear;
        ut.getSystemDate(&currYear);
        is >> year;
        if (!(year)) {
            m_state = "Invalid date value";

            return;
        }

        if (year >= 10000) {
            m_year = year / 10000;
            month = (year / 100) % 100;
            day = year % 100;
            if (m_year < 100)
                m_year += currYear / 100 * 100;
        }
        else {
            m_year = currYear;
            month = year / 100;
            day = year % 100;
        }

        m_month = month;
        m_day = day;

    }

    void Date::write(std::ostream& os) const {
        if (m_formatted) {
            os << std::setw(4) << std::setfill('0') << m_year << '/';
            os << std::setw(2) << std::setfill('0') << m_month << '/';
            os << std::setw(2) << std::setfill('0') << m_day;
        }
        else {
            os << std::setw(2) << std::setfill('0') << (m_year % 100);
            os << std::setw(2) << std::setfill('0') << m_month;
            os << std::setw(2) << std::setfill('0') << m_day;
        }
    }

    std::ostream& operator<<(std::ostream& ostr, const Date& date) {
        date.write(ostr);
        return ostr;
    }

    std::istream& operator>>(std::istream& istr, Date& date) {
        date.read(istr);
        return istr;
    }
}
