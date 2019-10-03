#include "IsoscelesTriangle.h"

IsoscelesTriangle::IsoscelesTriangle() : side(0.), base(0.) {

}

IsoscelesTriangle::IsoscelesTriangle(double side, double base) : side(side), base(base) {

}

IsoscelesTriangle::~IsoscelesTriangle() {}

void IsoscelesTriangle::setDimension(double side, double base) {
	this->side = side;
	this->base = base;
}

size_t IsoscelesTriangle::getSerializationSize()  const {
	return 2;
}

void IsoscelesTriangle::setDimension(const std::vector<double>& serializedInput) {
	std::vector<double> data = getSerializedData(serializedInput);
	side = data[0];
	base = data[1];
}


double IsoscelesTriangle::getSide() const {
	return side;
}

double IsoscelesTriangle::getBase() const {
	return base;
}

std::string IsoscelesTriangle::getClassShapeName() {
	return "IsoscelesTriangle";
}

std::string IsoscelesTriangle::getShapeName() const {
	return "IsoscelesTriangle";
};

double IsoscelesTriangle::computePerimeter() const {
	return side * 2 + base;
}

double IsoscelesTriangle::computeArea() const {
	// compute height from Pythagore theorem
	double halfBase = base / 2;

	double temp = side * side - halfBase * halfBase;
	if (temp <= 0.) return 0.;
	
	double height = sqrt(temp);

	return halfBase * height;

}

bool IsoscelesTriangle::isValid() const {
	return (side + side > base) && side > 0 && base > 0;
}

std::string IsoscelesTriangle::getInfoString() const {
	std::stringstream ss;
	ss << "IsoscelesTriangle(side=" << side << ",base=" << base << ")";
	return ss.str();
}