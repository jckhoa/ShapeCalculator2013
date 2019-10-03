#pragma once

#include "RectangleShape.h"


// The Square class describes a square from its side length.

class Square : public RectangleShape {

public:

	// Construct a square with side length set to zero.
	Square();

	// Construct a square from side length value.
	Square(double sideLength);

	// Destructor
	virtual ~Square();

	// Set side length of the square
	void setDimension(double sideLength);

	// Get side length of the square
	double getSide() const;

	// return the shape name of the class
	static std::string getClassShapeName();

	/////// Overriding functions ///////////

	// Return the number of double values used in serialized input
	size_t getSerializationSize() const;

	// Set input data from serialized double values
	void setDimension(const std::vector<double>& serializedInput);

	// Return the shape name of the object
	std::string getShapeName() const;

	// Compute and return the perimeter of the square
	// Return 0. if the square is invalid.
	double getPerimeter() const;

	// Compute and return the area of the square
	// Return 0. if the square is invalid.
	double getArea() const;

	// Return true if the square is valid (side length is positive), false otherwise.
	bool isValid() const;

	// Return the string containing the shape info
	std::string getInfoString() const;

private:

	double side; // side length of the square

};