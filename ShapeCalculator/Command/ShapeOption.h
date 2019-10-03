#pragma once

#include "ShapeOptionBase.h"

template <class T>
class ShapeOption : public ShapeOptionBase {

public:

	// Construct the Shape option base
	// optionName: set it to "r" if the command line option is to be "-r" for rectangle
	// arguments: a string listing arguments in order separated by space. 
	// For example, arguments = "width height" corresponds to command line option "-r width height"
	// optionDescription: describe the option. For example optionDescription = "Compute perimeter and area of a rectangle".
	// argumentDescription: a string describing in detail the arguments.
	ShapeOption(const std::string& optionName, const std::string& arguments
		, const std::string& optionDescription = "", const std::string& argumentDescription = "")
		: ShapeOptionBase(optionName, arguments, optionDescription, argumentDescription)
	{

	}

	// Overloading ShapeOptionBase class function
	// Return the string containing the results after shape computation
	std::string getShapeResult(const std::vector<double>& params) const {
		T shape;

		shape.setDimension(params);
		
		std::stringstream ss;
		ss << shape.getInfoString();
		if (shape.isValid()) {
			ss << " has " << shape.getPropertyString() << ".";
		}
		else {
			ss << " is invalid.";
		}
		
		return ss.str();
	}

	// Overloading OptionBase class function
	// Return the number of required arguments for shape computation
	size_t getArgumentCount() const {
		return T().getSerializationSize();
	}
};
