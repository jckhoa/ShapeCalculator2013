#pragma once

#include "Shape.h"
#include <sstream>

// The abstract class Shape2D is a base class for implementing 2D shapes.

class Shape2D : public Shape {

public:

	// Destructor
	virtual ~Shape2D() {}

	// Compute and return the perimeter of the 2D shape
	virtual double getPerimeter() const = 0;

	// Compute and return the area of the 2D shape
	virtual double getArea() const = 0;

	// Overload the function from class Shape
	// Return the string containing perimeter and area values.
	std::string getPropertyString() const {
		std::stringstream ss;
		ss << "(perimeter=" << getPerimeter() << ",area=" << getArea() << ")";
		return ss.str();
	}

};