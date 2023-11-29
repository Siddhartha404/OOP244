/* Citation and Sources...
Final Project Milestone 1
Module: Status
Filename: Status.h
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
#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
namespace sdds {
	class Status
	{
	private:
		char* m_description;
		int m_code;
	public:
		Status();
		~Status();
		Status(const Status& status);
		Status(const char* desc);

		Status& operator=(int newCode);
		Status& operator=(const Status& status);
		Status& operator=(const char* desc);

		operator int()const;
		operator const char* () const;
		operator bool()const;
		Status& clear();
	};
	std::ostream& operator<<(std::ostream& ostr, const Status& status);

}
#endif // !SDDS_STATUS_H