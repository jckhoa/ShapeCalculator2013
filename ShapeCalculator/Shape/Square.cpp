#include "Square.h"

Square::Square() : side(0.) {

}

Square::Square(double sideLength) : side(sideLength) {

}

Square::~Square() {}

void Square::setDimension(double sideLength) {
	side = sideLength;
}

size_t Square::getSerializationSize() const {
	return 1;
}

void Square::setDimension(const std::vector<double>& serializedInput) {
	std::vector<double> data = getSerializedData(serializedInput);
	side = data[0];
}

double Square::getSide() const {
	return side;
}

double Square::getWidth() const {
	return side;
}

double Square::getHeight() const {
	return side;
}

std::string Square::getClassShapeName() {
	return "Square";
}

std::string Square::getShapeName() const {
	return "Square";
};

bool Square::isValid() const {
	return side > 0;
}

std::string Square::getInfoString() const {
	std::stringstream ss;
	ss << "Square(side=" << side << ")";
	return ss.str();
}