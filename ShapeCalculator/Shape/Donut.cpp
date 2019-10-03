#include "Donut.h"

Donut::Donut() : ci(0.), ce(0.) {}

Donut::Donut(double radius1, double radius2) {
	setDimension(radius1, radius2);
}

Donut::~Donut() {}

void Donut::setDimension(double radius1, double radius2) {
	// assign the radius values to internal and external circles
	// make sure that the internal circle radius is smaller than the external circle radius

	if (radius1 < radius2) {
		ci.setDimension(radius1);
		ce.setDimension(radius2);
	}
	else {
		ci.setDimension(radius2);
		ce.setDimension(radius1);
	}
}

size_t Donut::getSerializationSize() const {
	return 2;
}

void Donut::setDimension(const std::vector<double>& serializedInput) {
	std::vector<double> data = getSerializedData(serializedInput);
	setDimension(data[0], data[1]);
}

double Donut::getInternalRadius() const {
	return ci.getRadius();
}

double Donut::getExternalRadius() const {
	return ce.getRadius();
}


std::string Donut::getClassShapeName() {
	return "Donut";
}

std::string Donut::getShapeName() const {
	return "Donut";
};

double Donut::getPerimeter() const {
	if (!isValid()) return 0.;
	return ci.getPerimeter() + ce.getPerimeter();
}

double Donut::getArea() const {
	if (!isValid()) return 0.;
	return ce.getArea() - ci.getArea();
}

bool Donut::isValid() const {
	return ci.isValid() && ce.isValid() && ci.getRadius() != ce.getRadius();
}

std::string Donut::getInfoString() const {
	std::stringstream ss;
	ss << "Donut(intern_radius=" << ci.getRadius() << ",extern_radius=" << ce.getRadius() << ")";
	return ss.str();
}