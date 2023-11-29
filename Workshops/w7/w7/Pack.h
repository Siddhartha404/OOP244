/*
#Name: Siddhartha Thapa Chhetri
#Student ID: 147913222
#Email: sthapa-chhetri2@myseneca.ca
#Section: ZAA
#Completion date: 2023-11-10
*/
#ifndef SDDS_PACK_H
#define SDDS_PACK_H
#include "Container.h"
namespace sdds {
	class Pack : public Container 
	{
	private:
		int m_unitSize;
		int m_numberOfUnits;
	public:
		Pack(const char* container, int maxSize, int unitSize = 330, int numberOfUnits = 0);
		int operator+=(int numToAdd);
		int operator-=(int numToRemove);
		// Queries
		int unit() const;
		int noOfUnits() const;
		int size() const;

		void clear(int packSize, int unitSize, const char* contener);
		std::ostream& print(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
	};
	std::ostream& operator<<(std::ostream& ostr, const Pack& pack);
	std::istream& operator>>(std::istream& istr, Pack& pack);
}
#endif // !SDDS_PACK_H
