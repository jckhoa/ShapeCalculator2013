#pragma once

#include "Shape.h"
#include <sstream>

// The abstract class Shape2D is a base class for implementing 2D shapes.

class Shape2D : public Shape {

public:

	// Destructor
	virtual ~Shape2D() {}

	// Compute and return the perimeter of the 2D shape
	// if the shape is invalid, zero is returned.
	double getPerimeter() const {
		if (!isValid()) return 0.;
		else return computePerimeter();
	};

	// Compute and return the area of the 2D shape
	// if the shape is invalid, zero is returned.
	double getArea() const {
		if (!isValid()) return 0.;
		else return computeArea();
	}

	// Overload the function from class Shape
	// Return the string containing perimeter and area values.
	std::string getPropertyString() const {
		std::stringstream ss;
		ss << "(perimeter=" << getPerimeter() << ",area=" << getArea() << ")";
		return ss.str();
	}

protected:
	// Compute and return the perimeter of the 2D shape
	virtual double computePerimeter() const = 0;

	// Compute and return the area of the 2D shape
	virtual double computeArea() const = 0;
};