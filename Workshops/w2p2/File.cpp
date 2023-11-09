/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  File.cpp
// Version 1.0
// Author   Fardad Soleimanloo
//Name: Siddhartha Thapa Chhetri
//Email: sthapa-chhetri2@myseneca.ca
//Student id: 147913222
//Date: 2023-09-25


// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include "File.h"

namespace sdds {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }

    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }

    bool read(char*& postalCode) {
        char tempcode[10]; // Temporary buffer for reading the name
        if (fscanf(fptr, "%10[^\n]\n", tempcode) == 1) {
            // If fscanf was successful, allocate memory for postacode
            postalCode = new char[strlen(tempcode) + 1];
            strcpy(postalCode, tempcode);
            return true; // Read successful
        }
        return false; // Read failed
    }

    bool read(int& population) {
        if (fscanf(fptr, "%d,", &population) == 1) {
            return true; // Read successful
        }
        return false; // Read failed
    }
}