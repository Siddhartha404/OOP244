//Name: Siddhartha Thapa Chhetri
//Email: sthapa-chhetri2@myseneca.ca
//Student id: 147913222
//Date: 2023-09-25

/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  File.h
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	bool read(char*& name);

}
#endif // !SDDS_FILE_H_