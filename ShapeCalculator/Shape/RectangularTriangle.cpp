#include "RectangularTriangle.h"

RectangularTriangle::RectangularTriangle() : s1(0.), s2(0.) {

}

RectangularTriangle::RectangularTriangle(double side1, double side2) : s1(side1), s2(side2) {

}

RectangularTriangle::~RectangularTriangle() {}

void RectangularTriangle::setDimension(double side1, double side2) {
	this->s1 = side1;
	this->s2 = side2;
}

size_t RectangularTriangle::getSerializationSize()  const {
	return 2;
}

void RectangularTriangle::setDimension(const std::vector<double>& serializedInput) {
	std::vector<double> data = getSerializedData(serializedInput);
	s1 = data[0];
	s2 = data[1];
}

double RectangularTriangle::getFirstSide() const {
	return s1;
}

double RectangularTriangle::getSecondSide() const {
	return s2;
}

std::string RectangularTriangle::getClassShapeName() {
	return "RectangularTriangle";
}

std::string RectangularTriangle::getShapeName() const {
	return "RectangularTriangle";
};

double RectangularTriangle::getPerimeter() const {
	if (!isValid()) return 0.;
	// using Pythagore theorem to compute the hypotenuse length
	double s3 = sqrt(s1 * s1 + s2 * s2);
	return s1 + s2 + s3;
}

double RectangularTriangle::getArea() const {
	if (!isValid()) return 0.;
	return s1 * s2 / 2;
}

bool RectangularTriangle::isValid() const {
	return s1 > 0 && s2 > 0;
}

std::string RectangularTriangle::getInfoString() const {
	std::stringstream ss;
	ss << "RectangularTriangle(side1=" << s1 << ",side2=" << s2 << ")";
	return ss.str();
}