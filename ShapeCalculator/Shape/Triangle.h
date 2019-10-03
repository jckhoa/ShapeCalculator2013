#pragma once

#include "TriangleShape.h"

// The Triangle class describes a triangular shape with its 3 side lengths.

class Triangle: public TriangleShape {

public:
	// Construct a triangle with the length of 3 sides set to zeros
	Triangle();

	// Construct a triangle with the length of 3 sides
	Triangle(double side1, double side2, double side3);

	// Destructor
	virtual ~Triangle();

	// Set the lengths of 3 sides of the triangle.
	void setDimension(double side1, double side2, double side3);

	// Return the first side of the triangle
	double getFirstSide() const;

	// Return the second side of the triangle
	double getSecondSide() const;

	// Return the third side of the triangle
	double getThirdSide() const;

	// return the shape name of the class
	static std::string getClassShapeName();

	/////// Overriding functions ///////////

	// Return the number of double values used in serialized input
	size_t getSerializationSize() const;

	// Set input data from serialized double values
	void setDimension(const std::vector<double>& serializedInput);

	// Return the shape name of the object
	std::string getShapeName() const;

	// Compute and return the perimeter of the triangle.
	// Return 0. if the triangle is invalid.
	double getPerimeter() const;

	// Compute and return the area of the triangle.
	// Return 0. if the triangle is invalid.
	double getArea() const;

	// Return true if the triangle is valid, false otherwise.
	// A valid triangle with side lengths a, b, and c, must satisfy 3 following conditions
	// (1) a + b > c (2) a + c > b (3) b + c > a
	bool isValid() const;

	// Return the string containing the shape info
	std::string getInfoString() const;

private:

	double a, b, c; // three sides of the triangle

};