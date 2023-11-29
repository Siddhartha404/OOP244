/*
#Name: Siddhartha Thapa Chhetri
#Student ID: 147913222
#Email: sthapa-chhetri2@myseneca.ca
#Section: ZAA
#Completion date: 2023-11-20
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Line.h"

using namespace std;
namespace sdds {
	Line::Line()
	{
		m_length = 0;
	}
	Line::Line(const char* label, int length) : LblShape(label), m_length(length) {

	}

	Line::~Line()
	{
	}

	void Line::getSpecs(std::istream& istr)
	{
		LblShape::getSpecs(istr);
		istr >> m_length;
		istr.ignore(10000, '\n');
	}

	void Line::draw(std::ostream& ostr) const
	{
		if (m_length > 0 && label() != nullptr) {
			ostr << label() << endl;

			for (int i = 0; i < m_length; i++) {
				ostr << "=";
			}
		}
	}

}