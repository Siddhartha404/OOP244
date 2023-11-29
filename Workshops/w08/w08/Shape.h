#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
namespace sdds {
	class Shape {
	public:
		virtual void draw(std::ostream& os) const = 0;
		virtual void getSpecs(std::istream& is) = 0;
		virtual ~Shape();
	};

	std::ostream& operator <<(std::ostream& ostr, const Shape& shape);
	std::istream& operator >>(std::istream& istr, Shape& shape);
}
#endif // !SDDS_SHAPE_H