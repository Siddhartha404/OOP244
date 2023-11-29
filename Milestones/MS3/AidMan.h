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

namespace sdds {
    class AidMan {
        char* m_filename{};
        Menu m_menu;
    public:
        AidMan(const char* filename);
        ~AidMan();
        int menu()const;
        void run();
    };
}

#endif // !SDDS_AIDMAN_H