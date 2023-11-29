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

		//operation overloading
		bool operator==(const Date& date) const;
		bool operator!=(const Date& date) const;
		bool operator<(const Date& date) const;
		bool operator>(const Date& date) const;
		bool operator<=(const Date& date) const;
		bool operator>=(const Date& date) const;
		operator bool()const;
		// State accessor method
		const Status& state() const;
		Date& formatted(bool value);

		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);

	};
	std::ostream& operator<<(std::ostream& ostr, const Date& date);
	std::istream& operator>>(std::istream& istr, Date& date);
}
#endif // !SDDS_DATE_H
