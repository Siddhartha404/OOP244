/*
#Name: Siddhartha Thapa Chhetri
#Student ID: 147913222
#Email: sthapa-chhetri2@myseneca.ca
#Section: ZAA
#Completion date: 2023-11-20
*/

#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include "LblShape.h"

namespace sdds {
    class Rectangle : public LblShape {
    private:
        int m_width;
        int m_height;

    public:
        Rectangle();
        Rectangle(const char* label, int width, int height);
        ~Rectangle();
        void getSpecs(std::istream& is);
        void draw(std::ostream& os) const;
    };
}

#endif // !SDDS_RECTANGLE_H
