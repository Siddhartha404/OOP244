/*
#Name: Siddhartha Thapa Chhetri
#Student ID: 147913222
#Email: sthapa-chhetri2@myseneca.ca
#Section: ZAA
#Completion date: 2023-11-20
*/
#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include "LblShape.h"

namespace sdds {
    class Line : public LblShape {
    private:
        int m_length;

    public:
        Line();
        Line(const char* label, int length);
        ~Line();
        void getSpecs(std::istream& istr);
        void draw(std::ostream& ostr) const;
    };
}

#endif // !SDDS_LINE_H