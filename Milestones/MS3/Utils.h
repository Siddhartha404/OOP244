/* Citation and Sources...
Final Project Milestone 1
Module: Utils
Filename: Utils.h
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
namespace sdds {
    // Testing date values for application testing and debugging
    // these values must not change at submission time.
    const int sdds_testYear = 2023;
    const int sdds_testMon = 10;
    const int sdds_testDay = 9;
    class Utils {
        bool m_testMode = false;
    public:
        // this function will be used to get the current system date or the test date if m_testMode is true
        void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);
        // this function will return the number of days in a month based on the year
        // 1<=mon<=12  year: four digit number (example: 2023)
        int daysOfMon(int mon, int year)const;
        // Puts the system date in test mode, where getSystemDate() function will return 2023, 12, 09
        // or whatever the three constant test dates are set to
        void testMode(bool testmode = true);
        //Safely allocates memory in the destination argument and copies the source into it.
        void alocpy(char*& destination, const char* source);
        //If the prompt is not null, it will display it. Then it performs a foolproof entry of an integer.
        int getint(const char* prompt = nullptr);
        //If the prompt is not null it will be displayed before getting a valid integer
        int getint(int min, int max, const char* prompt = nullptr, const char* errMes = nullptr);
    };
    extern Utils ut;  // provides global access to the ut instance in the Utils.cpp file
}
