# Shape Calculator

Purpose: compute geometric properties (such as perimeter and area) of primitive shapes (such as circle, rectangle, triangle, etc.)

1) The project solution structure
	Platform: The project was developed in C++, in Visual studio 2013 Community version under Windows 10.
	Hence open the VS solution file ShapeCalculator.sln with VS 2013.

	Solution structures: The solution contains two projects:
		- ShapeCalculator : contains codes for shape library and command line options
		- UnitTest : testing the code functions in the ShapeCalculator project.
	If one opens the solution using Visual Studio, one will see both projects.

	Compilation: 
		- Open the solution file with VS 2013 (other platforms not tested)
		- On the toolbar, select Release or Debug and x64 or x86 as target. Then select Build>Build Solution.
		- One will obtain the x64/ShapeCalculator.exe or x86/ShapeCalculator.exe in the same folder as this README.md file
		- In console, type 'ShapeCalculator.exe -h' for help information

	Run unit tests:
		- Open the solution file with VS 2013 (other platforms not tested)
		- On the toolbar, select Test>Windows>Test Explorer. The Test Explorer window will be opened.
		- Click Run All to run all the test
		- If all the test fails, on the toolbar,it can be due to the test running on a different architecture than the build. To fix it, select Test>Test Settings>Default Processor Architecture> x64 (or x86). Then click Run All again. 

2) The project folder structure: contain two sub folders
	ShapeCalculator: containing
		- Shape folder: contain source codes for shape classes
		- Command folder: contain source codes for implementing command line options
		- main.cpp: contain main function to enable command lines in the console 
	UnitTest: containing unit tests
	
3) Instructions for adding new shape and command line option for the new shape:
	
	Instructions for adding a new shape: make a class (for defining a new shape) inherit either
		- TriangleShape, RectangleShape, CircleShape or Shape2D: one must implement the following methods:
			+ "static std::string getClassShapeName()" and "std::string getShapeName() const": these methods must return the same string to enable downcasting
			+ "size_t getSerializationSize() const" and "void setDimension(const std::vector<double>& serializedInput)": these methods allow setting shape parameter from serialized double values. 
			+ "bool isValid() const": this method must return true for valid shape and false for invalid shape.
			+ "double getPerimeter() const" and "double getArea() const": these methods should return the perimeter and area of the shape. It is recommended that they return 0.0 for invalid shape.
			+ "std::string getInfoString() const": this method should return the shape info (identity, shape type, shape parameters, etc.)
		- Shape3D: one must implement all the methods shown above except getPerimeter() and getArea(). Besides, one must implement two additional methods:
			+ "double getVolume() const" and "double getSurfaceArea() const": these methods should return the volume and surface area of the shape. It is recommended that they return 0.0 for invalid shape.
	
		See examples from codes of Triangle (Triangle.h and Triangle.cpp) or Square (Square.h and Square.cpp)

	Instructions to add new command option for new shape class NewShape: suppose the NewShape requires four values to represent side lengths and one wishes to add the command for this shape as '-ns value1 value2 value3 value4', one may add one line below the following line in main.cpp: 

			parser.addOption<RectangularTriangle>("rt", "side1 side2", "Compute perimeter and area of a RectanglarTriangle");

		as such:

			parser.addOption<NewShape>("ns", "value1 value2 value3 value4", "Compute perimeter and area of a NewShape");

		Then include the header of the NewShape (for example 'NewShape.h') in main.cpp. See the content of main.cpp for example.
# ShapeCalculator2013
