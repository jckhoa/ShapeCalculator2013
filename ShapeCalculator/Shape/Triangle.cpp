#include "Triangle.h"

Triangle::Triangle() : a(0.), b(0.), c(0.) {

}

Triangle::Triangle(double side1, double side2, double side3) : a(side1), b(side2), c(side3) {

}

Triangle::~Triangle() {}

void Triangle::setDimension(double side1, double side2, double side3) {
	a = side1;
	b = side2;
	c = side3;
}

size_t Triangle::getSerializationSize() const {
	return 3;
}

void Triangle::setDimension(const std::vector<double>& serializedInput) {
	std::vector<double> data = getSerializedData(serializedInput);
	a = data[0];
	b = data[1];
	c = data[2];
}

double Triangle::getFirstSide() const {
	return a;
}

double Triangle::getSecondSide() const {
	return b;
}

double Triangle::getThirdSide() const {
	return c;
}

std::string Triangle::getClassShapeName() {
	return "Triangle";
}

std::string Triangle::getShapeName() const {
	return "Triangle";
};


bool Triangle::isValid() const {
	return (a + b > c) && (a + c > b) && (b + c > a);
}

std::string Triangle::getInfoString() const {
	std::stringstream ss;
	ss << "Triangle(side1=" << a << ",side2=" << b << ",side3=" << c << ")";
	return ss.str();
}