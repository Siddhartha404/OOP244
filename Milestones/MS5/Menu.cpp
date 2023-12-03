/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.cpp
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
#include<cstring>
#include "Utils.h"
#include "Menu.h"
using namespace std;
namespace sdds {
	Menu::Menu(const char* menu) : m_menuContent(nullptr), m_options(0)
	{
		int options = 0;
		if (menu != nullptr) {
			ut.alocpy(m_menuContent, menu);
			for (size_t i=0; i < strlen(menu); i++) {
				if (menu[i] == '\t') {
					options++;
				}
			}
			if (options > MAXMENU) {
				delete[] m_menuContent;
				m_menuContent = nullptr;
				m_options = 0;
			}
		}
		else
		{
			m_menuContent = nullptr;
		}

	}
	Menu::~Menu()
	{
		delete[] m_menuContent;
		m_menuContent = nullptr;
	}

	int Menu::run() const
	{
		int input = 0;
		if (m_menuContent) {
			int index = 1;

			cout << index << "- ";
			for (size_t i = 0; i < strlen(m_menuContent); i++) {
				if (m_menuContent[i] == '\t') {
					cout << endl;
					cout << ++index << "- ";
				}
				else cout << m_menuContent[i];
			}

			cout << endl << "---------------------------------" << endl << "0- Exit" << endl << "> ";

			do {
				input = ut.getint();
				if (input == -1) {
					cout << "Invalid Integer, retry: ";
				}
				if (input != -1 && (input < 0 || input > index))
				{
					cout << "Value out of range [0<=val<=" << index << "]: ";
				}

			} while (input < 0 || input > index);
			return input;
		}
		else{
			cout << "Invalid Menu!" << endl;
			return input;
		}
	}

	void Menu::print(int selected)
	{
		int counter = 1;
			for (size_t i = 0; i < strlen(m_menuContent); i++) {
				if (m_menuContent[i] == '\t') {
					counter++;
					i++;
				}
				if (counter == selected) {
					cout << m_menuContent[i];
				}
			}
	}
}
