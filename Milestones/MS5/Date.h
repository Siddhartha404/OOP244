/* Citation and Sources...
Final Project Milestone 1
Module: Date
Filename: Date.h
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
#ifndef SDDS_DATE_H
#define	SDDS_DATE_H
#include "Status.h"
const int MAX_YEAR = 2030;
const int MAX_MONTH = 12;
const int MIN_VAL = 1;
namespace sdds {
	class Date {
	private:
		int m_year;
		int m_month;
		int m_day;
		Status m_state;
		bool m_formatted;
		bool validate();
		int uniqueDateValue()const;

	public:

		Date();
		Date(int year, int month, int day);

		// Accessor methods
		int year() const { return m_year; }
		int month() const { return m_month; }
		int day() const { return m_day; }
		//operation overloading
		bool operator==(const Date& date) const;
		bool operator!=(const Date& date) const;
		bool operator<(const Date& date) const;
		bool operator>(const Date& date) const;
		bool operator<=(const Date& date) const;
		bool operator>=(const Date& date) const;
		
		// State accessor method
		Status state() const;
		void formatted(bool value);
		void read(std::istream& is);
		void write(std::ostream& os) const;

	};
	std::ostream& operator<<(std::ostream& ostr, const Date& date);
	std::istream& operator>>(std::istream& istr, Date& date);
}
#endif // !SDDS_DATE_H
