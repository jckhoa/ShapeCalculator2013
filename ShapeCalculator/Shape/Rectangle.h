#pragma once

#include "RectangleShape.h"

// The Rectangle class describes a rectangle from its width and height.

class Rectangle : public RectangleShape {

public:

	// Construct a square with width and height set to zeros
	Rectangle();

	// Construct a rectangle from width and height values
	Rectangle(double width, double height);

	// Desctructor
	virtual ~Rectangle();

	// Set the width and height of the rectangle
	void setDimension(double width, double height);

	// Return the width of the rectangle
	double getWidth() const;

	// Return the height of the rectangle
	double getHeight() const;

	// Return true if this rectangle is a square (width is equal to height), false otherwise.
	bool isSquare() const;

	// return the shape name of the class
	static std::string getClassShapeName();

	/////// Overriding functions ///////////

	// Return the number of double values used in serialized input
	size_t getSerializationSize() const;

	// Set input data from serialized double values
	void setDimension(const std::vector<double>& serializedInput);

	// Return the shape name of the object
	std::string getShapeName() const;

	// Compute and return the perimeter of the rectangle.
	// Return 0. if the rectangle is invalid.
	double getPerimeter() const;

	// Compute and return the area of the rectangle.
	// Return 0. if the rectangle is invalid.
	double getArea() const;

	// Return true if the rectangle is valid (width and height are positive), false otherwise.
	bool isValid() const;

	// Return the string containing the shape info
	std::string getInfoString() const;

private:

	double width; // width of the rectangle
	
	double height; // height of the rectangle

};