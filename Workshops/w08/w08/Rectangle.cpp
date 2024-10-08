/*
#Name: Siddhartha Thapa Chhetri
#Student ID: 147913222
#Email: sthapa-chhetri2@myseneca.ca
#Section: ZAA
#Completion date: 2023-11-20
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <iomanip>
#include "Rectangle.h"
#include "Line.h"

using namespace std;

namespace sdds {
	Rectangle::Rectangle() : LblShape(), m_width(0), m_height(0) {}

	Rectangle::Rectangle(const char* label, int width, int height): LblShape(label), m_width(width), m_height(height)
	{
		int value = strlen(label) + 2;
		if (m_height < 3 || m_width < value) {
			m_width = 0;
			m_height = 0;
		}
	}

	Rectangle::~Rectangle()
	{
	}

	void Rectangle::getSpecs(std::istream& istr)
	{
		LblShape::getSpecs(istr);
		istr >> m_width;
		istr.ignore(2000, ',');
		istr >> m_height;
		istr.ignore(2000, '\n');
	}
	void Rectangle::draw(std::ostream& os) const
	{
		if (m_width > 0 && m_height > 0) {
			os << "+";
			for (int i = 0; i < m_width - 2; i++) {
				os << "-";
			}
			os << "+" << endl;

			os << "|";
			os << setw((streamsize)m_width - 2) << setfill(' ') << left << label();
			os << "|" << endl;

			for (int i = 0; i < m_height - 3; i++) {
				os << "|" << setw((streamsize)m_width - 2) << " " << "|" << endl;
			}

			os << "+";
			for (int i = 0; i < m_width - 2; i++) {
				os << "-";
			}
			os << "+";
		}
	}
}
