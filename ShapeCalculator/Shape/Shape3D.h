#pragma once

#include "Shape.h"
#include <sstream>

// The abstract class Shape3D is a base class for implementing 3D shapes

class Shape3D : public Shape {

public:

	// Destructor
	virtual ~Shape3D() {}

	// Compute and return the volume of the 3D shape.
	virtual double getVolume() const = 0;

	// Compute and return the surface area of the 3D shape.
	virtual double getSurfaceArea() const = 0;

	// Overload the function from class Shape
	// Return the string containing volume and surface area values.
	std::string getPropertyString() const {
		std::stringstream ss;
		ss << "(volume=" << getVolume() << ",surfaceArea=" << getSurfaceArea() << ")";
		return ss.str();
	}

};