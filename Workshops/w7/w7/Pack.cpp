/*
#Name: Siddhartha Thapa Chhetri
#Student ID: 147913222
#Email: sthapa-chhetri2@myseneca.ca
#Section: ZAA
#Completion date: 2023-11-10
*/
#include <iostream>
#include "Pack.h"
using namespace std;
namespace sdds {
	Pack::Pack(const char* container, int maxSize, int unitSize, int numberOfUnits) : Container(container,maxSize* unitSize, numberOfUnits* unitSize), m_unitSize(unitSize), m_numberOfUnits(numberOfUnits)
	{
		if (unitSize <= 0) {
			setEmpty();
		}
	}
	int Pack::operator+=(int numToAdd)
	{
		int unitsAdded = Container::operator+=(numToAdd * m_unitSize) / m_unitSize;
		this->m_numberOfUnits += unitsAdded;
		return unitsAdded;
	}

	int Pack::operator-=(int numToRemove)
	{
		int unitsRemoved = Container::operator-=(numToRemove * m_unitSize) / m_unitSize;
		this->m_numberOfUnits -= unitsRemoved;
		return unitsRemoved;
	}
	int Pack::unit() const
	{
		return m_unitSize;
	}
	int Pack::noOfUnits()const
	{
		return volume() / m_unitSize;
	}
	int Pack::size() const
	{
		return capacity() / m_unitSize;
	}

	void Pack::clear(int packSize, int unitSize, const char* contener)
	{
		if (unitSize > 0)
		{
			Container::clear(packSize* unitSize, contener);
			m_unitSize = unitSize;
		}
		else {
			setEmpty();
		}
	}

	ostream& Pack::print(std::ostream& ostr) const
	{
		Container::print(ostr);
		if (*this) {
			ostr << ", " << noOfUnits() << " in a pack of " << size();
		}
		return ostr;
	}
	istream& Pack::read(std::istream& istr) {
		if (!*this) {
			cout << "Broken Container, adding aborted! Press <ENTER> to continue...";
			char newline;
			cin.get(newline);
			return istr;
		}

		if (noOfUnits() < size()) {
			cout << "Add to " << * this << endl;
			cout << "> ";
			int unitsToAdd;
			istr >> unitsToAdd;

			while (istr.fail() || unitsToAdd < 1 || unitsToAdd > size() - noOfUnits()) {
				istr.clear();
				istr.ignore(1000, '\n');
				cout << "Value out of range [1<=val<=" << (size() - noOfUnits()) << "]: ";
				istr >> unitsToAdd;
			}

			*this += unitsToAdd;
			cout << "Added " << unitsToAdd << endl;
		}
		else {
			cin.ignore(1000, '\n');
			cout << "Pack is full!, press <ENTER> to continue...";
			char newline;
			cin.get(newline);
		}
		return istr;
	}
	ostream& operator<<(std::ostream& ostr, const Pack& pack) {
		return pack.print(ostr);
	}
	istream& operator>>(std::istream& istr, Pack& pack) {
		return pack.read(istr);
	}


}