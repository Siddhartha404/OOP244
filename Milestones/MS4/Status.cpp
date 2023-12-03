/* Citation and Sources...
Final Project Milestone 1
Module: Status
Filename: Status.cpp
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
#include <cstring>
#include <iostream>
#include "Status.h"
#include "Utils.h"
using namespace std;
namespace sdds {
	Status::Status() : m_description(nullptr), m_code(0)
	{
	}
	Status::~Status()
	{
		clear();
	}
	Status::Status(const Status& status) : m_description(nullptr), m_code(0)
	{
		if (status.m_description != nullptr)
		{
			ut.alocpy(m_description, status.m_description);
			m_code = status.m_code;
		}
	}
	Status::Status(const char* desc) : m_description(nullptr), m_code(0)
	{
		if (desc != nullptr) {
			ut.alocpy(m_description, desc);
		}
		else {
			m_description = nullptr;
			m_code = 0;
		}
	}
	Status& Status::operator=(int newCode)
	{
		m_code = newCode;
		return *this;
	}
	Status& Status::operator=(const Status& status)
	{
		if (this != &status)
		{
			delete[] m_description;
			if (status.m_description != nullptr)
			{
				ut.alocpy(m_description, status.m_description);
				m_code = status.m_code;
			}
		}
		return *this;
	}
	Status& Status::operator=(const char* desc)
	{
		delete[] m_description;
		ut.alocpy(m_description, desc);
		return *this;
	}
	Status::operator int() const
	{
		return m_code;
	}
	Status::operator const char* () const
	{
		return m_description;
	}
	Status::operator bool() const
	{
		return m_description == nullptr;
	}

	Status& Status::clear()
	{
		delete[] m_description;
		m_description = nullptr;
		m_code = 0;
		return *this;
	}

	ostream& operator<<(ostream& ostr, const Status& status)
	{
		if (!bool(status))
		{
			if (int(status) != 0)
			{
				ostr << "ERR#" << int(status) << ": " << (const char*)status;
			}
			else
			{
				ostr << (const char*)status;
			}
		}
		return ostr;
	}

}