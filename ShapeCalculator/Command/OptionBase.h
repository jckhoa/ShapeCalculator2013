#pragma once

#include "Shape.h"
#include <vector>
#include <sstream>

// The abstract class OptionBase is a base class for defining options in command line

class OptionBase {
public:
	// Construct the option base
	// optionName: set it to "r" if the command line option is to be "-r" for rectangle
	// arguments: a string listing arguments in order separated by space. 
	// For example, arguments = "width height" corresponds to command line option "-r width height"
	// optionDescription: describe the option. For example optionDescription = "Compute perimeter and area of a rectangle".
	// argumentDescription: a string describing in detail the arguments.
	OptionBase(const std::string& optionName, const std::string& arguments, const std::string& optionDescription = "", const std::string& argumentDescription = "")
		: optName(optionName), argStr(arguments), optDescription(optionDescription), argDescription(argumentDescription)
	{

	}

	// Destructor
	virtual ~OptionBase() {}

	// Return the option name. For example: return "r" for rectangle, the command line option will be "-r"
	const std::string& getOptionName() const {
		return optName;
	}

	// Return arguments string. For example: return "width height" for rectangle
	const std::string& getArguments() const {
		return argStr;
	}

	// Return the option description string
	const std::string& getOptionDescription() const {
		return optDescription;
	}

	// Return the argument description string
	const std::string& getArgumentDescription() const {
		return argDescription;
	}

	// Return error message on arguments
	std::string getArgumentErrorMessage() const {
		std::stringstream ss;
		ss << "Wrong argument type or number of arguments for option -" << getOptionName() << ".";
		return ss.str();
	}

	// Return full command string. For example: return "-r width height" for rectangle
	std::string getFullCommand() const {
		std::stringstream ss;
		ss << "-" << getOptionName() << " " << getArguments();
		return ss.str();
	}


	// Return the number of required arguments for shape computation. Must be overridden
	virtual size_t getArgumentCount() const = 0;

private:

	std::string optName;  // option name
	std::string argStr;   // string listing arguments in order
	std::string optDescription; // description of the option
	std::string argDescription; // description of the arguments
};