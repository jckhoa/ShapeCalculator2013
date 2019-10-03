#pragma once


#include "TriangleShape.h"

// The IsoscelesTriangle class describes an isosceles triangle from its side and base lengths.

class IsoscelesTriangle : public TriangleShape {

public:

	// Construct an isosceles triangle with side and base lengths set to zero.
	IsoscelesTriangle();

	// Construct an isosceles triangle from side and base lengths.
	IsoscelesTriangle(double side, double base);

	// Destructor
	virtual ~IsoscelesTriangle();

	// Set the side and base lengths of the isosceles triangle
	void setDimension(double side, double base);

	// Return the side length of the isosceles triangle
	double getSide() const;

	// Return the base length of the isosceles triangle
	double getBase() const;

	// Return the shape name of the class
	static std::string getClassShapeName();

	/////// Overriding functions ///////////

	// Return the number of double values used in serialized input
	size_t getSerializationSize() const;

	// Set input data from serialized double values
	void setDimension(const std::vector<double>& serializedInput);

	// Return the shape name of the object
	std::string getShapeName() const;

	// Compute and return the perimeter of the isosceles triangle
	// Return 0. if the isosceles triangle is invalid.
	double getPerimeter() const;

	// Compute and return the area of the isosceles triangle
	// Return 0. if the isosceles triangle is invalid.
	double getArea() const;

	// Return true if the isoseles triangle is valid, i.e. valid condition for base and side lengths, false otherwise.
	bool isValid() const;

	// Return the string containing the shape info
	std::string getInfoString() const;

private:

	double side; // side length of the isosceles triangle
	
	double base; // base length of the isoceles triangle

};