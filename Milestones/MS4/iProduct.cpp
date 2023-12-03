/* Citation and Sources...
Final Project Milestone 3
Module: iProduct
Filename: iProduct.cpp
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
#include"iProduct.h"
using namespace std;
namespace sdds {

    std::ostream& operator<<(std::ostream& ostr, const iProduct& product) {
        return product.display(ostr);
    }

    std::istream& operator>>(std::istream& istr, iProduct& product) {
        return product.read(istr);
    }
}