/* Citation and Sources...
Final Project Milestone 3
Module: Item
Filename: Item.h
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
#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H

#include "iProduct.h"
#include "Status.h"
namespace sdds {

    class Item : public iProduct {
        double m_price;
        int m_quantityOnHand;
        int m_neededQuantity;
        char* m_description;
        bool m_isLinear;

    protected:
        Status m_status;
        int m_sku;

    public:
        Item();
        Item(const char* description, int sku, double price = 0.0, int neededQuantity = 0);
        Item(const Item& src);
        Item& operator=(const Item& src);
        virtual ~Item();
        void clear();
        // iProduct interface implementations
        int readSku(std::istream& istr);
        int operator-=(int qty);
        int operator+=(int qty);
        operator double() const;
        operator bool() const;
        int qtyNeeded() const;
        int qty() const;
        void linear(bool isLinear);
        bool linear()const;
        std::ofstream& save(std::ofstream& ofstr) const;
        std::ifstream& load(std::ifstream& ifstr);
        std::ostream& display(std::ostream& ostr) const;
        std::istream& read(std::istream& istr);
        bool operator==(int sku) const;
        bool operator==(const char* description) const;
    };
}

#endif // !SDDS_ITEM_H
