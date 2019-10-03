#pragma once

#include "OptionBase.h"

// The abstract class ShapeOptionBase is for defining command line options of shape computation

class ShapeOptionBase : public OptionBase {

public:

	// Construct the Shape option base
	// optionName: set it to "r" if the command line option is to be "-r" for rectangle
	// arguments: a string listing arguments in order separated by space. 
	// For example, arguments = "width height" corresponds to command line option "-r width height"
	// optionDescription: describe the option. For example optionDescription = "Compute perimeter and area of a rectangle".
	// argumentDescription: a string describing in detail the arguments.
	ShapeOptionBase(const std::string& optionName, const std::string& arguments
		, const std::string& optionDescription = "", const std::string& argumentDescription = "")
	: OptionBase(optionName, arguments, optionDescription, argumentDescription)
	{

	}

	// Destructor
	virtual ~ShapeOptionBase() {}

	// Return the string containing the results after shape computation
	virtual std::string getShapeResult(const std::vector<double>& params) const = 0;

private:

};