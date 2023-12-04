/* Citation and Sources...
Final Project Milestone 3
Module: Item
Filename: item.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <iomanip>
#include <cstring>
#include "Utils.h"
#include "Item.h"


using namespace std;
namespace sdds {

    Item::Item()
        : m_price(0.0), m_quantityOnHand(0), m_neededQuantity(0), m_description(nullptr), m_isLinear(false), m_sku(0) {
    }

    Item::Item(const char* description, int sku, double price, int neededQuantity)
        : m_price(price), m_quantityOnHand(0), m_neededQuantity(neededQuantity), m_isLinear(false), m_sku(sku) {
        if (description != nullptr) {
            ut.alocpy(m_description, description);
        }
        else {
            m_description = nullptr;
        }
    }

    Item::Item(const Item& src) : m_description(nullptr) {
        *this = src;
    }

    Item& Item::operator=(const Item& src) {
        if (this != &src) {
            m_price = src.m_price;
            m_quantityOnHand = src.m_quantityOnHand;
            m_neededQuantity = src.m_neededQuantity;
            m_isLinear = src.m_isLinear;
            m_status = src.m_status;
            m_sku = src.m_sku;

            delete[] m_description;
            if (src.m_description != nullptr) {
                ut.alocpy(m_description, src.m_description);
            }
            else {
                m_description = nullptr;
            }
        }
        return *this;
    }

    Item::~Item() {
        delete[] m_description;
    }

    int Item::readSku(std::istream& istr)
    {
        cout << "SKU: ";
        m_sku = ut.getint(40000, 99999);
        return m_sku;
    }

    int Item::operator-=(int qty)
    {
        return m_quantityOnHand -= qty;
    }

    int Item::operator+=(int qty)
    {
        return m_quantityOnHand += qty;
    }

    int Item::qtyNeeded() const {
        return m_neededQuantity;
    }

    int Item::qty() const {
        return m_quantityOnHand;
    }

    void Item::linear(bool isLinear)
    {
        m_isLinear = isLinear;
    }

    bool Item::linear() const
    {
        return m_isLinear;
    }

    std::ofstream& Item::save(std::ofstream& ofstr) const
    {
        if (operator bool()) {
            ofstr << m_sku << '\t' << m_description << '\t' << m_quantityOnHand << '\t' << m_neededQuantity << '\t';
            ofstr << fixed << setprecision(2) << m_price;
        }

        return ofstr;
    }

    std::ifstream& Item::load(std::ifstream& ifstr)
    {
        delete[] m_description;
        m_description = nullptr;
        ifstr >> m_sku;
        if (ifstr.fail()) {
            m_status = "Input file stream read failed!";
        }
        else {
            char temp[2000];
            ifstr.ignore();
            ifstr.getline(temp, 2000, '\t');
            ut.alocpy(m_description,temp);
            ifstr >> m_quantityOnHand;
            ifstr.ignore();
            ifstr >> m_neededQuantity;
            ifstr.ignore();
            ifstr >> m_price;
            ifstr.ignore(1);
        }
        return ifstr;
    }

    Item::operator double() const {
        return m_price;
    }

    Item::operator bool() const {
        return (m_description && m_neededQuantity >= 0 && m_quantityOnHand >= 0 && m_price > 0 && m_sku > 0);
    }
    std::ostream& Item::display(std::ostream& ostr) const
    {
        if (!m_status) {
            ostr << m_status;
        }
        else {
            if (m_isLinear) {
                ostr << setw(5) << m_sku << " | "
                    << left << setw(35) << setfill(' ') << (strlen(m_description) > 35 ? string(m_description, 35) : m_description)
                    << " | " << right << setw(4) << m_quantityOnHand << " | "
                    << right << setw(4) << m_neededQuantity << " | "
                    << right << setw(7) << fixed << setprecision(2) << m_price << " |";
            }
            else {
                ostr << "AMA Item:" << endl
                    << std::setw(5) << m_sku << ": "
                    << m_description << endl
                    << "Quantity Needed: " << m_neededQuantity << endl
                    << "Quantity Available: " << m_quantityOnHand << endl
                    << "Unit Price: $" << fixed << setprecision(2) << m_price << endl;
                double needed = (m_neededQuantity - m_quantityOnHand) * m_price;
                    ostr << "Needed Purchase Fund: $" << fixed << setprecision(2) << needed << endl;
            }
        }
        return ostr;
    }
    istream& Item::read(std::istream& istr) {
        delete[] m_description;
        m_description = nullptr;

        cout << "AMA Item:" << endl
            << "SKU: " << m_sku << endl
            << "Description: ";

        istr.ignore();
        char temp[2000];
        istr.getline(temp, 2000);
        ut.alocpy(m_description, temp);

        bool success = false;
        cout << "Quantity Needed: ";
        m_neededQuantity = ut.getint(1, 9999);

        success = false;
        std::cout << "Quantity On Hand: ";
        while (!success) {
            if (!(istr >> m_quantityOnHand)) {
                std::cout << "Invalid Integer, retry: ";
                istr.clear();
                istr.ignore(numeric_limits<std::streamsize>::max(), '\n');
            }
            else if (m_quantityOnHand < 0 || m_quantityOnHand > m_neededQuantity) {
                std::cout << "Value out of range [0<=val<=22]: ";
            }
            else {
                success = true;
            }
        }

        success = false;
        std::cout << "Unit Price: $";
        while (!success) {
            if (!(istr >> m_price)) {
                cout << "Invalid number, retry: ";
                istr.clear();
                istr.ignore(numeric_limits<std::streamsize>::max(), '\n');
            }
            else if (m_price < 0.0 || m_price > 9999.0) {
                std::cout << "Value out of range [0.00<=val<=9999.00]: ";
            }
            else {
                success = true;
            }
        }

        return istr;
    }
    bool Item::operator==(int sku) const
    {
        return m_sku == sku;
    }
    bool Item::operator==(const char* description) const
    {
        if (description == nullptr || m_description == nullptr) {
            return false;
        }
        if (isdigit(description[0]) && std::stoi(description) == m_sku) {
            return true;
        }
        if (strstr(m_description, description) != nullptr) {
            return true;
        }

        return false;
    }

    void Item::clear() {
        m_status.clear();
    }
}
