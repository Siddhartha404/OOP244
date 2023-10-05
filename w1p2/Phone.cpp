#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "cStrTools.h"

using namespace std;
namespace sdds {

    void phoneDir(const char* programTitle, const char* fileName) {
        //neccesary variables
        char nameInFile[51];
        char nameInFileLow[51];
        char nameEntered[51];
        char name[51];
        char areaCode[4];
        char prefix[4]; 
        char num[5];
        int flag1 = 1;
        

        cout << programTitle << " phone direcotry" << endl;
        cout << "-------------------------------------------------------" << endl;

        FILE* file = fopen(fileName, "r");

        if (file == nullptr) {
            cout << fileName << " file not found!" << endl;
            cout << "Thank you for using " << programTitle << " directory." << endl;
            return;
        }

        while (flag1 == 1) {
            cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
            cout << "> ";
            cin >> nameEntered;

            if (strCmp(nameEntered, "!") == 0) {
                cout << "Thank you for using " << programTitle << " directory." << endl;
                flag1 = 0;
                break;
            }

            int found = 0;
            int flag2 = 1;

            while (flag2 = 1) {
                
                int result = fscanf(file, "%[^\t]\t%s\t%s\t%s\n", nameInFile, areaCode, prefix, num);

                if (result == EOF) {
                    flag2 = 0; // End of file reached
                    break;
                }

                toLowerCaseAndCopy(nameInFileLow, nameInFile);
                toLowerCaseAndCopy(name, nameEntered);

                if (strStr(nameInFileLow,name)) {
                    cout << nameInFile << ": (" << areaCode << ") " << prefix << "-" << num << endl;
                    found = 1;
                }
            }

            if (found == 0) {
                cout << "No matching records found." << endl;
            }

            rewind(file);
        }

        fclose(file);
    }

}
