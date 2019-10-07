#pragma once

#include "Shape2D.h"

// The abstract RectangleShape class is a base class for defining all the rectangular shapes.

class RectangleShape : public Shape2D {

public:
	virtual double getWidth() const = 0;
	virtual double getHeight() const = 0;

	virtual ~RectangleShape() = 0 {

	}

protected:
	virtual double computePerimeter() const {
		return (getWidth() + getHeight()) * 2;
	}

	virtual double computeArea() const {
		return getWidth() * getHeight();
	}
};