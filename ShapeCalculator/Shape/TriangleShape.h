#pragma once

#include "Shape2D.h"

// The abstract TriangleShape class is a base class for defining all the trianglar shapes.

class TriangleShape: public Shape2D {

public:

	virtual ~TriangleShape() = 0 {

	}

protected:
	double computePerimeterFromSides(double a, double b, double c) const {
		return a + b + c;
	}
};