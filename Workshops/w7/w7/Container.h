/*
#Name: Siddhartha Thapa Chhetri
#Student ID: 147913222
#Email: sthapa-chhetri2@myseneca.ca
#Section: ZAA
#Completion date: 2023-11-10
*/
#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H
namespace sdds {
    class Container {


    private:
        char m_content[51];
        int m_capacity;
        int m_contentVolume;
    protected:
        void setEmpty();
        int capacity() const;
        int volume() const;
    public:
        Container(const char* content, int capacity, int contentVolume = 0);
        int operator+=(int value);
        int operator-=(int value);
        operator bool() const;
        
        void clear(int capacity, const char* content);
        std::ostream& print(std::ostream& ostr) const;
        std::istream& read(std::istream& istr);
    };
    std::ostream& operator<<(std::ostream& ostr, const Container& container);
    std::istream& operator>>(std::istream& istr, Container& container);
}
#endif // !SDDS_CONTAINER_H
