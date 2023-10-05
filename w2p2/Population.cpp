//==============================================
// Name:           Siddhartha Thapa Chhetri
// Student ID:     147913222
// Email:          sthapa-chhetri2@myseneca.ca
// Date:           2023-09-25
//==============================================

#include <iostream>
#include "Population.h"
#include "File.h"
#include <cstring>

using namespace std;

namespace sdds {
    // Global variables:
    int noOfPostalCode;
    Postalcode* postalCode;

    bool startsWith(const char* cString, const char* subString) {
        return strstr(cString, subString) == cString;
    }

    bool getPostalCode(char* postal_code_prefix) {
        cout << "Population Report" << endl;
        cout << "-----------------" << endl;
        cout << "Enter postal code:" << endl;
        cout << ">";
        cin >> postal_code_prefix;
        if (strcmp(postal_code_prefix, "!") == 0) {
            return false;
        }
        else {
            return true;
        }
    }

    bool load(const char* filename, const char* partial_postal_code_prefix) {
        bool check = false;
        if (openFile(filename)) {
            noOfPostalCode = noOfRecords();
            postalCode = new Postalcode[noOfPostalCode];
            int validRecords = 0;  // Keep track of valid records

            for (int i = 0; i < noOfPostalCode; i++) {
                // Assuming PostalCode has code and population as char* and int
                if (read(postalCode[i].m_postal_code_prefix)) {
                    // Check if the postal code prefix matches the filter
                    if (startsWith(postalCode[i].m_postal_code_prefix, partial_postal_code_prefix)) {
                        validRecords++;
                    }
                }
                else {
                    check = false;
                    break;  // Exit the loop if there's an issue reading data
                }
            }

            if (validRecords > 0) {
                check = true;
                noOfPostalCode = validRecords;  // Update the count to valid records
            }
            else {
                check = false;
            }

            closeFile();
        }
        return check;
    }

    bool load(const char* filename) {
        bool check = false;
        if (openFile(filename)) {
            noOfPostalCode = noOfRecords();
            postalCode = new Postalcode[noOfPostalCode];
            for (int i = 0; i < noOfPostalCode; i++) {
                // Assuming PostalCode has code and population as char* and int
                if (read(postalCode[i].m_postal_code_prefix)) {
                    check = true;
                }
                else {
                    check = false;
                    break;  // Exit the loop if there's an issue reading data
                }
            }
            closeFile();
        }
        return check;
    }

    void display(const Postalcode& postalCode) {
        cout << postalCode.m_postal_code_prefix << ":  " << postalCode.m_population << endl;
    }

    void display() {
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;
        for (int i = 0; i < noOfPostalCode; i++) {
            cout << i + 1 << "- ";
            display(postalCode[i]);
        }
    }

    void deallocateMemory() {
        delete[] postalCode;
        postalCode = nullptr;
    }
}
