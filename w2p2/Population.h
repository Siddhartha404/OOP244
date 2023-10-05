//Name: Siddhartha Thapa Chhetri
//Email: sthapa-chhetri2@myseneca.ca
//Student id: 147913222
//Date: 2023-09-25

/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  Population.h
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {
	struct Postalcode {
		char* m_postal_code_prefix;
		int m_population;
	};

	// returns true of the cstring starts with subString
	bool startsWith(const char* cString, const char* subString);

	//returns false if "!" is entred
	bool getPostalCode(char* postal_code_prefix);

	//loads all the record with the postal code that start with the partial_postal_code_prefix
	bool load(const char* filename, const char* partial_postal_code_prefix);
	bool load(const char *filename);
	//function to display the report
	void display(const Postalcode& postalCode);
	void display();
	//Function to deallocagte all the dynamic memory
	void deallocateMemory();
}
#endif // SDDS_POPULATION_H_