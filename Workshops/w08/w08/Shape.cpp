#include <iostream>
#include "Shape.h"

using namespace std;
namespace sdds {
	ostream& operator<<(std::ostream& ostr, const Shape& shape) {
		shape.draw(ostr);
		return ostr;
	};

	istream& operator>>(std::istream& istr, Shape& shape) {
		shape.getSpecs(istr);
		return istr;
	};

	Shape::~Shape() {

	};
}