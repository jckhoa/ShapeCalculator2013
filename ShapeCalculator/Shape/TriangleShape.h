#pragma once

#include "Shape2D.h"

// The abstract TriangleShape class is a base class for defining all the trianglar shapes.

class TriangleShape: public Shape2D {

public:

	virtual ~TriangleShape() = 0 {

	}

	virtual double getFirstSide() const = 0;
	virtual double getSecondSide() const = 0;
	virtual double getThirdSide() const = 0;

protected:
	virtual double computePerimeter() const {
		return getFirstSide() + getSecondSide() + getThirdSide();
	}

	virtual double computeArea() const {
		// Use Heron's formula to compute its area
		double p = computePerimeter() / 2; // compute half perimeter
		double temp = p * (p - getFirstSide()) * (p - getSecondSide()) * (p - getThirdSide());

		if (temp <= 0.) return 0.;
		else return sqrt(temp);
	}
};