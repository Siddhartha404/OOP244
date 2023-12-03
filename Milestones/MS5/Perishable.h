/* Citation and Sources...
Final Project Milestone 4
Module: Perishable
Filename: Perishable.cpp
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
#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H
#include "Item.h"
#include "Date.h"

namespace sdds {
    class Perishable : public Item {
        Date m_expiryDate;
        char* m_instructions;

    public:
        Perishable();
        ~Perishable();

        const Date& expiry() const;
        operator bool() const override;
        // Rule of three
        Perishable(const Perishable& other);
        Perishable& operator=(const Perishable& other);

        // Virtual overrides
        std::ofstream& save(std::ofstream& ofstr) const override;
        std::ostream& display(std::ostream& ostr) const override;
        std::ifstream& load(std::ifstream& ifstr) override;
        std::istream& read(std::istream& istr) override;
        int readSku(std::istream& istr) override;
    };
}

#endif // !SDDS_PERISHABLE_H
