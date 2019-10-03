#include "Circle.h"

#include <iostream>
#include <vector>


#include "Circle.h"
#include "Donut.h"
#include "Triangle.h"
#include "IsoscelesTriangle.h"
#include "RectangularTriangle.h"
#include "Square.h"
#include "Rectangle.h"

#include "ArgumentParser.h"

int main(int argc, char *argv[]) {

	// Create an argument parser
	ArgumentParser parser;

	// Add command line option for each shape
	parser.addOption<Circle>("c", "radius", "Compute perimeter and area of a Circle");
	parser.addOption<Donut>("d", "internalRadius externalRadius", "Compute perimeter and area of a Donut");
	parser.addOption<Rectangle>("r", "width height", "Compute perimeter and area of a Rectangle");
	parser.addOption<Square>("s", "side", "Compute perimeter and area of a Square");
	parser.addOption<Triangle>("t", "side1 side2 side3", "Compute perimeter and area of a Triangle");
	parser.addOption<IsoscelesTriangle>("it", "side base", "Compute perimeter and area of a IsoscelesTriangle");
	parser.addOption<RectangularTriangle>("rt", "side1 side2", "Compute perimeter and area of a RectanglarTriangle");

	std::string errorMessage;

	// Process the command line and print out results or errors if any in the console
	if (parser.process(argc, argv, errorMessage)) {
		std::cout << parser.getResults() << std::endl;
	}
	else {
		std::cout << errorMessage << std::endl;
		std::cout << std::endl << parser.getHelpMessage() << std::endl;
	}

	return 0;
}