#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H

#include "Shape.h"

namespace sdds {
    class LblShape : public Shape {
    private:
        char* m_label;
    protected:
        const char* label() const;    
    public:
        LblShape();  // Default constructor
        LblShape(const char* label);  // Constructor with label
        ~LblShape();

        LblShape& operator=(const LblShape&) = delete;

        // Implementation of pure virtual function
        void getSpecs(std::istream& istr);

    };
}

#endif // !SDDS_LBLSHAPE_H
