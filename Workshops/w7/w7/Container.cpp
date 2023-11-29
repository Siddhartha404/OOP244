/*
#Name: Siddhartha Thapa Chhetri
#Student ID: 147913222
#Email: sthapa-chhetri2@myseneca.ca
#Section: ZAA
#Completion date: 2023-11-10
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include "Container.h"
using namespace std;
namespace sdds {
    Container::Container(const char* content, int capacity, int contentVolume) {
        if (content != nullptr && contentVolume <= capacity) {
            strncpy(m_content, content, 50);
            m_content[50] = '\0';
            m_capacity = capacity;
            m_contentVolume = contentVolume;
        }
        else {
            setEmpty();
        }
    }

    int Container::operator+=(int value)
    {
        int volumeAdded = value;
        if ((m_contentVolume + value) > m_capacity) {
            volumeAdded = m_capacity - m_contentVolume;
        }
        m_contentVolume += volumeAdded;
        return volumeAdded;
    }

    int Container::operator-=(int value)
    {
        int valueRemoved = value;
        if (value >= m_contentVolume) {
            valueRemoved = m_contentVolume;
        }
        m_contentVolume -= valueRemoved;
        return valueRemoved;
    }

    Container::operator bool() const
    {
        return m_content[0] != '\0' && m_capacity > 0 && m_contentVolume <= m_capacity;
    }

    void Container::clear(int capacity, const char* content)
    {
        if (capacity > 0 && content != nullptr) {
            Container tempContainer(content, capacity, 0);
            *this = tempContainer;
        }
        else {
            setEmpty();
        }
    }

    ostream& Container::print(ostream& ostr) const
    {
        if (*this) {
            ostr << m_content << ": (" << m_contentVolume << "cc/" << m_capacity << ")";
        }
        else {
            ostr << "****: (**cc/***)";
        }
        return ostr;
    }

    istream& Container::read(std::istream& istr)
    {
        if (*this) {
            int value;
            cout << "Add to " << m_content << ": (" << m_contentVolume << "cc/" << m_capacity << ")" << endl;
            cout << "> ";
            istr >> value;

            if (istr.fail()) {
                istr.clear();
                istr.ignore(1000, '\n');
                cout << "Invalid Integer, retry: ";
            }
            else if (value < 1) {
                istr.ignore(1000, '\n');
                cout << "Value out of range [1<=val<=" << m_capacity << "]: ";
            }
            else if (value > m_capacity - m_contentVolume) {
                value = m_capacity - m_contentVolume;
                *this += value;
                cout << "Added " << value << " CCs" << endl;
            }
            else {
                *this += value;
                cout << "Added " << value << " CCs" << endl;
            }
        }
        else {
            cin.ignore(1000, '\n');
            cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
            char newline;
            cin.get(newline);
        }
        return istr;
    }

    void Container::setEmpty() {
        m_content[0] = '\0';
        m_capacity = 0;
        m_contentVolume = 0;
    }
    int Container::capacity() const
    {
        return m_capacity;
    }
    int Container::volume() const
    {
        return m_contentVolume;
    }

    ostream& operator<<(ostream& ostr, const Container& container) {
        return container.print(ostr);
    }

    istream& operator>>(istream& istr, Container& container) {
        return container.read(istr);
    }

}