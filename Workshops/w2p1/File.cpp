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
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }
   
    bool read(char*& name) {
        char tempName[128]; // Temporary buffer for reading the name
        if (fscanf(fptr, "%127[^\n]\n", tempName) == 1) {
            // If fscanf was successful, allocate memory for name
            name = new char[strlen(tempName) + 1];
            strcpy(name, tempName);
            return true; // Read successful
        }
        return false; // Read failed
    }
    bool read(int& number) {
        if (fscanf(fptr, "%d,", &number) == 1) {
            return true; // Read successful
        }
        return false; // Read failed
    }
    bool read(double& salary) {
        if (fscanf(fptr, "%lf,", &salary) == 1) {
            return true; // Read successful
        }
        return false; // Read failed
    }
}