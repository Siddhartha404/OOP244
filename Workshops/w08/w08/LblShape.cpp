/*
#Name: Siddhartha Thapa Chhetri
#Student ID: 147913222
#Email: sthapa-chhetri2@myseneca.ca
#Section: ZAA
#Completion date: 2023-11-20
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include "LblShape.h"
using namespace std;
namespace sdds {
	const char* LblShape::label() const
	{
		return m_label;
	}
	LblShape::LblShape() : m_label(nullptr){}

	LblShape::LblShape(const char* label):m_label(nullptr)
	{
		if (label != nullptr) {
			delete[] m_label;
			m_label = new char[strlen(label) + 1];
			strcpy(m_label, label);
		}

	}

	LblShape::~LblShape()
	{
		delete[] m_label;
	}
	void LblShape::getSpecs(std::istream& istr)
	{
		char temp[250];
		istr.getline(temp, 250, ',');

		// Allocate memory for the label and copy the Cstring
		delete[] m_label;
		m_label = new char[strlen(temp) + 1];
		strcpy(m_label, temp);
	}
}