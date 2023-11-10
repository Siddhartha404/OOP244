/*
#Name: Siddhartha Thapa Chhetri
#Student ID: 147913222
#Email: sthapa-chhetri2@myseneca.ca
#Section: ZAA
#Completion date: 2023-11-08
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include "HealthCard.h"
using namespace std;
namespace sdds {
	HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[])
	{
		set(name, number, vCode, sNumber);
	}

    HealthCard::HealthCard(const HealthCard& hc)
    {
        *this = hc;
    }

    HealthCard& HealthCard::operator=(const HealthCard& hc)
    {
        if (this != &hc) {
            set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
        }
        return *this;
    }

    HealthCard::~HealthCard()
    {
        setEmpty();
    }

    HealthCard::operator bool() const
    {
        if (m_name != nullptr) {
            return true;
        }
        return false;
    }

    std::ostream& HealthCard::print(std::ostream& ostr, bool toFile) const
    {
        if (*this) { 
            if (toFile) {
                ostr << m_name << ", ";
                printIDInfo(ostr);
                ostr << endl;
            }
            else {
                ostr.width(50);
                ostr.fill('.');
                ostr.setf(ios::left);
                ostr << m_name;
                printIDInfo(ostr);
            }
        }
        return ostr;
    }

    std::istream& HealthCard::read(std::istream& istr)
    {
        char name[MaxNameLength]{ '\0' };
        long long number{ 0 };
        char vCode[3]{ 0 };
        char sNumber[10]{ 0 };

        istr.get(name, MaxNameLength, ',');
        extractChar(istr, ',');
        istr >> number;
        extractChar(istr, '-');
        istr.get(vCode, 3, ',');
        extractChar(istr, ',');
        istr.get(sNumber, 10, '\n');
        extractChar(istr, '\n');

        if (istr) {
            set(name, number, vCode, sNumber);
        }
        else {
            istr.clear();
            istr.ignore(10000, '\n');
        }
        return istr;
    }

    bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const
    {
        if (!name || !name[0]) {
            return false;
        }

        if (number <= 999999999 || number >= 9999999999) {
            return false;
        }

        if (!vCode || strlen(vCode) != 2) {
            return false;
        }

        if (!sNumber || strlen(sNumber) != 9) {
            return false;
        }

        return true;
    }

    void HealthCard::setEmpty()
    {
        delete[] m_name;
        m_name = nullptr;
    }

    void HealthCard::allocateAndCopy(const char* name)
    {
        delete[] m_name;
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
    }

    void HealthCard::extractChar(istream& istr, char ch) const
    {
        int nextChar = istr.peek();
        if (nextChar == ch) {
            istr.ignore();
        }
        else {
            istr.ignore(10000, ch);
            istr.setstate(ios::failbit);
        }
    }

    ostream& HealthCard::printIDInfo(ostream& ostr) const
    {
        ostr << m_number << "-" << m_vCode << ", " << m_sNumber;
        return ostr;
    }

    void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[])
	{
        setEmpty();
        if (validID(name, number, vCode, sNumber))
        {
            allocateAndCopy(name);
            m_number = number;
            strcpy(m_vCode, vCode);
            strcpy(m_sNumber, sNumber);
        }
        
	}
	
    ostream& operator<<(ostream& ostr, const HealthCard& hc)
    {
        if (hc)
        {
            hc.print(ostr, false);
        }
        else
        {
            ostr << "Invalid Health Card Record";
        }

        return ostr;
    }

    istream& operator>>(istream& istr, HealthCard& hc)
    {
        return hc.read(istr);
    }

}