#pragma once

#include "Circle.h"

// The Donut (or Couronne) class describes a donut shape from the radii of two concentric circles.

class Donut : public CircleShape {

public:

	// Construct a donut with the radii set to zero
	Donut();

	// Construct a donut from the internal and external radii. Their order is not important.
	Donut(double radius1, double radius2);

	// Desctructor
	virtual ~Donut();

	// Set the internal and external radii. Their order is not important.
	void setDimension(double radius1, double radius2);

	// Return the internal radius of the donut.
	double getInternalRadius() const;

	// Return the external radius of the donut.
	double getExternalRadius() const;

	// Return the shape name of the class
	static std::string getClassShapeName();

	/////// Overriding functions from base classes ///////////

	// Return the number of double values used in serialized input
	size_t getSerializationSize() const;

	// Set input data from serialized double values
	void setDimension(const std::vector<double>& serializedInput);

	// Return the shape name of the object
	std::string getShapeName() const;

	// Compute and return the perimeter of the donut
	// Return 0. if the donut is invalid.
	double getPerimeter() const;

	// Compute and return the area of the donut
	// Return 0. if the donut is invalid.
	double getArea() const;

	// Return true if the donut is valid (i.e. the internal and external circle are valid 
	// and their outlines do not overlap), false otherwise
	bool isValid() const;

	// Return the string containing the shape info
	std::string getInfoString() const;

private:

	Circle ci; // internal circle
	
	Circle ce; // external circle

};