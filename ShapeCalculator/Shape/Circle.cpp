#include "Circle.h"

Circle::Circle() : radius(0.) {}

Circle::Circle(double radius) : radius(radius) {}

Circle::~Circle() {}

void Circle::setDimension(double radius) {
	this->radius = radius;
}

size_t Circle::getSerializationSize() const {
	return 1;
}

void Circle::setDimension(const std::vector<double>& serializedInput) {
	std::vector<double> data(serializedInput);
	data.resize(getSerializationSize(), 0.);
	radius = data[0];
}

double Circle::getRadius() const {
	return radius;
}

std::string Circle::getClassShapeName() {
	return "Circle";
}

std::string Circle::getShapeName() const {
	return "Circle";
};

double Circle::getPerimeter() const {
	if (!isValid()) return 0.;
	return radius * M_PI * 2;
}

double Circle::getArea() const {
	if (!isValid()) return 0.;
	return radius * radius * M_PI;
}

bool Circle::isValid() const {
	return radius > 0;
}

std::string Circle::getInfoString() const {
	std::stringstream ss;
	ss << "Circle(radius=" << radius << ")";
	return ss.str();
}