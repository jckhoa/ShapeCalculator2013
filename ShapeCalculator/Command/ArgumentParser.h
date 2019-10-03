#pragma once


#include <map>

#include "ShapeOption.h"

// The class ArgumentParser is used for parsing argument from command line for the Shape Calculator program
// Note: in the future, this class could be implemented following the Singleton pattern.

class ArgumentParser {

public:
	
	// Constructor
	ArgumentParser();

	// Destructor
	~ArgumentParser();

	//Return the current available options
	const std::map<std::string, ShapeOptionBase*>& getOptions() const;

	//Add an option for a shape
	template<class T>
	void addOption(const std::string& optionName, const std::string& arguments
		, const std::string& optionDescription = "", const std::string& argumentDescription = "") {
		options[optionName] = new ShapeOption<T>(optionName, arguments, optionDescription, argumentDescription);
	}

	// parse command line arguments.
	// Return true if there is no error, false otherwise.
	// Error messages is written to errorMessage if any.
	bool process(int argc, char* argv[], std::string& errorMessage);

	// Return help message
	std::string getHelpMessage() const;

	// Return results
	std::string getResults() const;

private:

	// forbid copy constructor
	ArgumentParser(const ArgumentParser& other) {}
	
	// forbid assignment operator
	ArgumentParser operator=(const ArgumentParser& other) {}

	// forbid move constructor
	ArgumentParser(ArgumentParser&& other) {}

	//forbid move assignment operator
	ArgumentParser operator=(ArgumentParser&& other) {}

	// Parse parameters for shape calculation, this function is used inside the process(...) function
	bool parseOptionArgument(const ShapeOptionBase& option, int &index, int argc, char* argv[], std::vector<double>& params);

private:

	// Store available options
	std::map<std::string, ShapeOptionBase*> options;
	
	// Store the results
	std::vector<std::string> results;

};