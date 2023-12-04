/* Citation and Sources...
Final Project Milestone 4
Module: Perishable
Filename: Perishable.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include "Perishable.h"
#include "Utils.h"
using namespace std;
namespace sdds {
	Perishable::Perishable(): Item(), m_instructions(nullptr)
	{
	}
	Perishable::~Perishable()
	{
		delete[] m_instructions;
	}
	const Date& Perishable::expiry() const
	{
		return m_expiryDate;
	}
	Perishable::operator bool() const
	{
		return m_sku != 0;
	}
	Perishable::Perishable(const Perishable& other): Item(other)
	{
		m_instructions = nullptr;
		*this = other;
	}
	Perishable& Perishable::operator=(const Perishable& other)
	{
		if (this != &other) {
        Item::operator=(other);

        // Check if m_instructions is already allocated
        if (m_instructions != nullptr) {
            delete[] m_instructions;
            m_instructions = nullptr;
        }

        m_expiryDate = other.m_expiryDate;
        if (other.m_instructions != nullptr) {
            ut.alocpy(m_instructions, other.m_instructions);
        }
    }
    return *this;
	}
	std::ofstream& Perishable::save(std::ofstream& ofstr) const
	{
		if (ofstr) {
			Item::save(ofstr);
			ofstr << '\t' << (m_instructions ? m_instructions : "") << '\t';
			Date temp(m_expiryDate.year(), m_expiryDate.month(), m_expiryDate.day());
			temp.formatted(false);

			ofstr << temp;//check if need of endl
		}
		return ofstr;
	}
	std::ostream& Perishable::display(std::ostream& ostr) const
	{
		if (!m_status) {
			ostr << m_status;
		}
		else {
			if (Item::linear()) {
				Item::display(ostr);  // Call the display of the base class in linear mode

				ostr << (m_instructions && *m_instructions ? '*' : ' ');
				ostr << m_expiryDate;
			}
			else {
				ostr << "Perishable ";
				Item::display(ostr);
				ostr << "Expiry date: ";
				ostr << m_expiryDate; 
				cout << endl;
				if (m_instructions && *m_instructions) {
					ostr << "Handling Instructions: " << m_instructions << endl;
				}
			}
		}
		return ostr;
	}
	std::ifstream& Perishable::load(std::ifstream& ifstr)
	{
		Item::load(ifstr);

		if (ifstr.fail()) {
			m_status = "Input file stream read (perishable) failed!";
			return ifstr;
		}

		delete[] m_instructions;
		m_instructions = nullptr;
		char temp[1000];
		if (ifstr.getline(temp, 1000, '\t') && isalpha(temp[0])) {
			m_instructions = new char[strlen(temp) + 1];
			strcpy(m_instructions, temp);
		}

		ifstr >> m_expiryDate;
		ifstr.ignore();

		return ifstr;
	}

	std::istream& Perishable::read(std::istream& istr)
	{
		Item::read(istr);
		delete[] m_instructions;
		m_instructions = nullptr;

		std::cout << "Expiry date (YYMMDD): ";
		istr >> m_expiryDate;
		istr.ignore(1000, '\n');

		std::cout << "Handling Instructions, ENTER to skip: " << endl;
		char firstChar = istr.peek();
		if (firstChar != '\n') {
			m_instructions = new char[1000];
			istr.getline(m_instructions, 1000);
		}
		else {
			istr.ignore();
		}
		if (istr.fail()) {
			m_status = "Perishable console date entry failed!";
		}

		return istr;
	}
	int Perishable::readSku(std::istream& istr)
	{
		cout << "SKU: ";
		m_sku = ut.getint(10000, 39999);
		return m_sku;
	}
}
