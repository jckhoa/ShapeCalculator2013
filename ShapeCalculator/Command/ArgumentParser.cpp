#include "ArgumentParser.h"

ArgumentParser::ArgumentParser() {

}

ArgumentParser::~ArgumentParser() {
	// deallocate memory for OptionBase
	for (auto& item : options) {
		delete item.second;
	}
}

const std::map<std::string, ShapeOptionBase*>& ArgumentParser::getOptions() const {
	return options;
}

bool ArgumentParser::parseOptionArgument(const ShapeOptionBase& option, int &index, int argc, char* argv[], std::vector<double>& params) {
	for (unsigned int i = 0; i < option.getArgumentCount(); ++i) {
		++index;
		if (index >= argc) return false;
		double value = 0.;
		std::stringstream ss(argv[index]);
		ss >> value;
		if (ss.fail()) return false;
		params.push_back(value);
	}
	return true;
}

bool ArgumentParser::process(int argc, char* argv[], std::string& errMessage) {
	
	// initialize error message and results
	errMessage = "";
	results.clear();

	if (argc <= 1) { 
		errMessage = "Please provide more options";
		return false; 
	}
	else {
		std::string optionName("");
		int index = 1;
		while (index < argc) {
			if (argv[index][0] == '-') {
				// get the string part after '-'
				optionName = std::string(argv[index]).substr(1);
			}
			else {
				std::stringstream ss;
				ss << "Error. Expecting the " << index << "th parameter to be an option, not argument.";
				errMessage = ss.str();
				return false;
			}
			if (optionName == "h") {
				return false;
			}

			// search for the optionName in options
			auto iter = options.find(optionName);
			
			if (iter == options.end()) {
				// the optionName is not found
				std::stringstream ss;
				ss << "The option '-" << optionName << "' is not found. ";
				errMessage = ss.str();
				return false;
			} 

			const ShapeOptionBase& option = *iter->second;

			std::vector<double> params;

			// parse the next arguments depending on the option name
			if (!parseOptionArgument(option, index, argc, argv, params)) {
				// failure getting the correct arguments for this option
				errMessage = option.getArgumentErrorMessage();
				return false;
			}

			// add the result string to results
			results.push_back(option.getShapeResult(params));
			
			++index;
		}
	}
	return true;
}

std::string ArgumentParser::getHelpMessage() const {
	// construct help message
	std::stringstream ss;
	ss << "ShapeCalculator calculate geometric measures (perimeters, areas, etc.) of shapes such as circle, square, rectangle, etc." << std::endl;
	ss << "Syntax: ShapeCalculator.exe [options]" << std::endl;
	ss << "Current available options: " << std::endl;
	ss << "-h : show this help message." << std::endl;
	for (const auto& item : options) {
		const ShapeOptionBase& option = *item.second;
		if (option.getOptionName() == "h") continue;
		ss << "-" << option.getOptionName() 
			<< " (" << option.getFullCommand() << ") : " << option.getOptionDescription() << ". " 
			<< option.getArgumentDescription() << std::endl;
	}
	return ss.str();
}

std::string ArgumentParser::getResults() const {
	std::stringstream ss;
	for (const auto& result : results) {
		ss << result << std::endl;
	}
	return ss.str();
}