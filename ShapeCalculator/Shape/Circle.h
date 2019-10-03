#pragma once

#include "CircleShape.h"

// The Circle (or Disque) class describes a circular shape from a radius.

class Circle : public CircleShape {

public:

	// Construct a circle with radius set to zero.
	Circle();

	// Construct a circle from the radius value.
	Circle(double radius);

	// Desctructor
	virtual ~Circle();

	// Set the radius of the circle
	void setDimension(double radius = 0.);

	// Return the radius of the circle
	double getRadius() const;

	// Return the shape name of the class
	static std::string getClassShapeName();

	/////// Overriding functions from base classes ///////////

	// Return the number of double values used in serialized input
	size_t getSerializationSize() const;

	// Set input data from serialized double values
	void setDimension(const std::vector<double>& serializedInput);

	// Return the shape name of the object
	std::string getShapeName() const;

	// Compute and return the perimeter of the circle.
	// Return 0. if the circle is invalid.
	double getPerimeter() const;

	// Compute and return the area of the circle
	// Return 0. if the circle is invalid.
	double getArea() const;

	// Return true if the circle is valid (the radius is positive), false otherwise.
	bool isValid() const;

	// Return the string containing the shape info
	std::string getInfoString() const;

private:

	// Radius of the circle
	double radius;

};