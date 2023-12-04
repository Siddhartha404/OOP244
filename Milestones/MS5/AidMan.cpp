/* Citation and Sources...
Final Project Milestone 5
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
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include "AidMan.h"
#include "Utils.h"
#include "Date.h"
#include "Perishable.h"
using namespace std;
namespace sdds {
	AidMan::AidMan() : m_filename(nullptr), m_menu("List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSort\tShip Items\tNew/Open Aid Database") {
	}
	void AidMan::save() const
	{
		if (m_filename != nullptr) {
			ofstream ofstr(m_filename);
			for (int i = 0; i < m_numOfItems; i++) {
				m_items[i]->save(ofstr);
				ofstr << endl;
			};
			ofstr.close();
		};
	}
	void AidMan::deallocate()
	{
		for (int i = 0; i < m_numOfItems; i++) {
			delete m_items[i];

		};
		m_numOfItems = 0;
	}

	bool AidMan::load() {
		save();
		deallocate();
		cout << "Enter file name: ";
		char tempName[10000];
		cin >> tempName;
		delete[] m_filename;
		m_filename = new char[strlen(tempName) + 1];
		strcpy(m_filename, tempName);
		ifstream ifstr(m_filename);
		int noRecordsLoaded = 0;
		if (ifstr.is_open()) {
			while (ifstr.peek() != EOF) {
				char c = ifstr.peek();
				int x = c - 48;
				if (x >= 1 && x <= 3) {
					m_items[m_numOfItems] = new Perishable;
				}
				else if (x >= 4 && x <= 9) {
					m_items[m_numOfItems] = new Item;
				}
				else {
					ifstr.setstate(ios::failbit);

				};
				m_items[m_numOfItems]->load(ifstr);

				if (m_items[m_numOfItems]) {
					noRecordsLoaded += 1;
					m_numOfItems += 1;
				}
				else {
					delete m_items[m_numOfItems];
				};

			};
		}
		else {
			cout << "Failed to open FN for reading!" << endl;
			cout << "Would you like to create a new data file?" << endl;
			cout << "1- Yes!" << endl;
			cout << "0- Exit" << endl;
			cout << ">";
			int optionSelected = (int)ut.getint(0, 1);
			if (optionSelected == 1) {
				ofstream ofstr(m_filename);
				ofstr.close();
			};

		};
		cout << noRecordsLoaded << " records loaded!" << endl << endl;

		bool returnValue;
		if (noRecordsLoaded > 0) {
			returnValue = true;

		}
		else {
			returnValue = false;

		};

		return returnValue;
	}




	AidMan::AidMan(const char* filename) : m_filename(nullptr), m_menu("List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSort\tShip Items\tNew/Open Aid Database"), m_items{ nullptr }
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
			cout << "Data file: " << m_filename;
		}
		else
		{
			cout << "Data file: No file";
		}
		cout << endl;
		return m_menu.run();
	}
	AidMan::~AidMan() {
		delete[] m_filename;
		deallocate();
	}

	void AidMan::run() {
		int input;
		do {
			input = menu();
			if (input != 0 && m_filename == nullptr && input != 7) {
				input = 7;

			}
			if (input == 0) {
				cout << "Exiting Program!" << endl;
			}
			else {
				cout << endl << "****";
				m_menu.print(input);
				cout << "****" << endl;
			}
			if (input == 7) {
				load();
			}
			if (input == 1) {
				list();
			}
			if (input == 2) {
				addItem();
			}
			if (input == 3) {
				removeItem();
			}
		} while (input != 0);
		save();
	}
	int AidMan::list(const char* sub_desc)
	{
		int rowNum = 0;
		int number = 0;
		bool validInput = true;
		cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
		cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
		for (int i = 0; i < m_numOfItems; i++)
		{

			if (sub_desc == nullptr)
			{
				m_items[i]->linear(true);
				cout << "   " << i + 1 << " | ";
				m_items[i]->display(cout);
				rowNum++;
				cout << endl;
			}
			else if (sub_desc) {

				cout << "   " << i + 1 << " | ";
				m_items[i]->display(cout);
				rowNum++;
				cout << endl;
			}
		}
		cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;

		do {
			cout << "Enter row number to display details or <ENTER> to continue:" << endl;
			cout << "> ";
			cin.ignore();
			if (cin.peek() == '\n') {

				cout << "\n";
				break;
			}
			cin >> number;
			if (number >= 1 && number <= rowNum) {
				m_items[number - 1]->linear(false);
				m_items[number - 1]->display(cout);
				cout << '\n' << '\n';

			}
			else {
				cout << "Invalid input. Please enter a valid row number." << endl;
				cin.clear();
				cin.ignore(100000, '\n');
			}

			cin.get();

		} while (!validInput);


		return rowNum;
	}
	int AidMan::search(int sku) const
	{
		for (int i = 0; i < m_numOfItems; i++)
		{
			if (m_items[i]->operator==(sku))
			{
				return i; 
			}
		}
		return -1;
	}

	void AidMan::addItem()
	{
		if (m_numOfItems >= sdds_max_num_items)
		{
			cout << "Database full!" << endl;
			return;
		}

		cout << "1- Perishable" << endl;
		cout << "2- Non-Perishable" << endl;
		cout << "-----------------" << endl;
		cout << "0- Exit" << endl;
		cout << "> ";

		int choice;
		cin >> choice;

		if (choice == 0)
		{
			cout << "Aborted" << endl;
			return;
		}

		iProduct* newItem = nullptr;

		if (choice == 1)
		{
			newItem = new Perishable();
		}
		else if (choice == 2)
		{
			newItem = new Item();
		}

		if (newItem == nullptr)
		{
			cout << "Memory allocation failed!" << endl;
			return;
		}

		int sku = newItem->readSku(cin);

		int existingIndex = search(sku);

		if (existingIndex != -1)
		{
			cout << "Sku: " << sku << " is already in the system, try updating quantity instead." << endl << endl;
			delete newItem;
			return;
		}

		newItem->read(cin);

		if (*newItem)
		{
			m_items[m_numOfItems++] = newItem;
		}
		else
		{
			newItem->display(cout);
			delete newItem;
		}
	}
}