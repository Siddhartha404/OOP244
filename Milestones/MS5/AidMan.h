/* Citation and Sources...
Final Project Milestone 2
Module: AidMan
Filename: AidMan.h
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
#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include "Menu.h"
#include "iProduct.h"

namespace sdds {
    const int sdds_max_num_items = 100;
    class AidMan {
        char* m_filename{};
        Menu m_menu;
        iProduct* m_items[sdds_max_num_items];
        int m_numOfItems{};

        // Private member functions
        void saveData() const;
        void deallocate();
        bool load(const char* file);
    public:
        AidMan();
        AidMan(const char* filename);
        ~AidMan();
        int menu()const;
        void run();
        operator bool()const { return m_filename && m_numOfItems; };
        int list(const char* sub_desc = nullptr);
    };
}

#endif // !SDDS_AIDMAN_H