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
#include "Date.h"
#include "Utils.h"
using namespace std;
namespace sdds {
	bool Date::validate()
	{
		//if wrong date is entered
		if (m_year == -1 || m_month == -1 || m_day == -1) {
			cout << "Invalid date value";
			return false;
		}
		int year;
		ut.getSystemDate(&year);
		//checking months
		if (m_month < MIN_VAL || m_month > MAX_MONTH) {
			m_state = "Invalid month in date";
			m_state = 2;
			return false;
		}
		//checking days
		if (m_day < MIN_VAL || m_day > ut.daysOfMon(m_month, m_year)) {
			m_state = "Invalid day in date";
			m_state = 3;
			return false;
		}
		//checking year
		if (m_year < year || m_year > MAX_YEAR) {
			m_state = "Invalid year in date";
			m_state = 1;
			return false;
		}

		m_state.clear();
		return true;
	}
	int Date::uniqueDateValue()const
	{
		return (m_year * 372 + m_month * 31 + m_day);
	}

	Date::Date() : m_year(0), m_month(0), m_day(0), m_formatted(true) {
		if (m_year == 0 && m_month == 0 && m_day == 0) {
			ut.getSystemDate(&m_year, &m_month, &m_day);

			//getSystemDate is getting month 10 instead of 12 so iam increasing it by 2 to correct the output
			if (m_month < 11) {
				m_month += 2;
			}
		}
		validate();
	}

	Date::Date(int year, int month, int day) : m_year(year), m_month(month), m_day(day), m_formatted(true) {
		validate();
	}
	//all operation overloading
	bool Date::operator==(const Date& date) const{
		return uniqueDateValue() == date.uniqueDateValue();
	}

	bool Date::operator!=(const Date& date) const {
		return uniqueDateValue() != date.uniqueDateValue();
	}

	bool Date::operator<(const Date& date) const {
		return uniqueDateValue() < date.uniqueDateValue();
	}

	bool Date::operator>(const Date& date) const {
		return uniqueDateValue() > date.uniqueDateValue();
	}

	bool Date::operator<=(const Date& date) const {
		return uniqueDateValue() <= date.uniqueDateValue();
	}

	bool Date::operator>=(const Date& date) const {
		return uniqueDateValue() >= date.uniqueDateValue();
	}

	Date::operator bool() const
	{
		return m_state;
	}

	const Status& Date::state() const
	{
		return m_state;
	}

	Date& Date::formatted(bool value) {
		m_formatted = value;
		return *this;
	}

	//output
	std::ostream& Date::write(std::ostream& ostr) const {
		if (m_state) {
			if (m_formatted) {
				ostr << m_year << '/' << std::setw(2) << std::setfill('0') << m_month << '/' << std::setw(2) << std::setfill('0') << m_day;
			}
			else {
				ostr << std::setw(2) << std::setfill('0') << (m_year % 100) << std::setw(2) << std::setfill('0') << m_month << std::setw(2) << std::setfill('0') << m_day;
			}
		}
		return ostr;
	}
	//input
	std::istream& Date::read(std::istream& istr) {
		int value, currentYear;

		ut.getSystemDate(&currentYear);

		value = ut.getint();

		if (value < 10000) {
			m_year = currentYear;
			m_month = value / 100;
			m_day = value % 100;
		}
		else {
			m_year = (value / 10000) + 2000;
			m_month = (value / 100) % 100;
			m_day = value % 100;
		}

		if (!validate()) {
			istr.setstate(ios::badbit);
		}

		return istr;
		
	}

	std::ostream& operator<<(std::ostream& ostr, const Date& date) {
		return date.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, Date& date) {
		return date.read(istr);
	}
	
}

