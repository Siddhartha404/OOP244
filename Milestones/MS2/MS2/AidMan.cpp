/* Citation and Sources...
Final Project Milestone 2
Module: AidMan
Filename: AidMan.cpp
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
#include<iostream>
#include "AidMan.h"
#include "Utils.h"
#include "Date.h"
using namespace std;
namespace sdds {
	AidMan::AidMan(const char* filename) : m_filename(nullptr), m_menu("List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSort\tShip Items\tNew/Open Aid Database")
	{
		if (filename != nullptr) {
			ut.alocpy(m_filename, filename);
		}
		else {
			m_filename = nullptr;
		}
	}
	int AidMan::menu() const
	{
		cout << "Aid Management System" << endl;
		cout << "Date: " << Date() << endl;
		if (m_filename)
		{
			cout << "Data file: " << m_filename << endl;
		}
		else
		{
			cout << "Data file: No file" << endl;
		}
		cout << endl;
		return m_menu.run();
	}
	AidMan::~AidMan() {
		delete[] m_filename;
		m_filename = nullptr;
	}

	void AidMan::run() {
		int input;
		do {
			input = menu(); 
			if (input == 0) { 
				cout << "Exiting Program!" << endl; 
			}
			else {
				cout << endl << "****";
				m_menu.print(input);
				cout << "****" << endl << endl;
			}
		} while (input != 0);
	}
}

