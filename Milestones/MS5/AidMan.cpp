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
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<cstring>
#include "AidMan.h"
#include "Utils.h"
#include "Date.h"
#include "Perishable.h"
using namespace std;
namespace sdds {
	AidMan::AidMan() : m_filename(nullptr), m_menu("List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSort\tShip Items\tNew/Open Aid Database") {
	}
	void AidMan::saveData() const
	{
		if (m_filename) {
			ofstream file(m_filename);
			if (file.is_open()) {
				for (int i = 0; i < m_numOfItems; i++) {
					if (m_items[i]) {
						m_items[i]->save(file);
						file << endl;
					}
				}
				file.close();
			}
		}
	}
	void AidMan::deallocate()
	{
		for (int i = 0; i < m_numOfItems; i++) {
			delete m_items[i];
			m_items[i] = nullptr;
		}
		delete[] m_filename;
		m_filename = nullptr;

		m_numOfItems = 0;
	}
	bool AidMan::load(const char* file)
	{
		deallocate(); // Deallocate existing resources

		if (file != nullptr) {
			ut.alocpy(m_filename, file);
		}

		ifstream inFile(m_filename);
		if (!inFile.is_open()) {
			cout << "Failed to open " << m_filename << " for reading!" << endl;
			cout << "Would you like to create a new data file?" << endl;
			cout << "1- Yes!" << endl;
			cout << "0- Exit" << endl;
			cout << "> ";

			int choice;
			cin >> choice;

			if (choice == 1) {
				ofstream outFile(m_filename);
				outFile.close(); // Create an empty file
			}
			return false;
		}

		// Loop to read records from the file
		while (!inFile.eof()) {
			char recordType;
			inFile >> ws; // Skip leading whitespaces

			if (inFile.peek() == EOF) {
				break; // Reached the end of the file
			}

			inFile.get(recordType);

			iProduct* newItem = nullptr;

			if (isdigit(recordType)) {
				if (recordType == 'P') {
					newItem = new Perishable();
				}
				else if (recordType == 'N') {
					newItem = new Item();
				}
				else {
					// Unrecognized record type, set the ifstream into an invalid state
					inFile.setstate(ios::failbit);
				}

				if (newItem != nullptr) {
					newItem->load(inFile);
					if (inFile.good()) {
						// The loaded item is in a good state
						m_items[m_numOfItems++] = newItem;
					}
					else {
						// The loaded item is not in a good state, delete it
						delete newItem;
					}
				}
			}
			else {
				// If the next character is not recognized as a valid digit,
				// set the ifstream into an invalid state
				inFile.setstate(ios::failbit);
				break;
			}
		}

		inFile.close();
		return m_numOfItems > 0;
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
			if (input != 0 && m_filename == nullptr && input != 7) {
				input = 7;
				
			}
			if (input == 0) { 
				cout << "Exiting Program!" << endl; 
			}
			else {
				cout << endl << "****";
				m_menu.print(input);
				cout << "****" << endl << endl;
			}
			if (input == 7) {
				cout << "enter the filename: ";
				char filename[1000];
				cin >> filename;
				load(filename);
				cout << m_numOfItems << endl;
			}
			if (input == 1) {
				list();
			}
		} while (input != 0);
		saveData();
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
}

