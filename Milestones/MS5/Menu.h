/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.h
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
#ifndef SDDS_MENU_H
#define SDDS_MENU_H

namespace sdds {
	const int MAXMENU = 15;
	class Menu
	{
	private:
		char* m_menuContent;
		int m_options;
	public:
		Menu(const char* menu = nullptr);
		~Menu();
		int run()const;
		void print(int selected);
	};
}

#endif // !SDDS_MENU_H



