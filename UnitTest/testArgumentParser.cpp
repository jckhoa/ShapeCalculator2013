#include "stdafx.h"
#include "CppUnitTest.h"


#include "Circle.h"
#include "Donut.h"
#include "Triangle.h"
#include "IsoscelesTriangle.h"
#include "RectangularTriangle.h"
#include "Square.h"
#include "Rectangle.h"

#include "ArgumentParser.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTestArgumentParser)
	{
	public:

		//Test the argument option '-c' for computing Circle shape
		TEST_METHOD(TestArgumentParser_CircleOption)
		{
			ArgumentParser parser;

			parser.addOption<Circle>("c", "radius", "Compute perimeter and area of a Circle");
			parser.addOption<Donut>("d", "internalRadius externalRadius", "Compute perimeter and area of a Donut");
			parser.addOption<Rectangle>("r", "width height", "Compute perimeter and area of a Rectangle");
			parser.addOption<Square>("s", "side", "Compute perimeter and area of a Square");
			parser.addOption<Triangle>("t", "side1 side2 side3", "Compute perimeter and area of a Triangle");
			parser.addOption<IsoscelesTriangle>("it", "side base", "Compute perimeter and area of a IsoscelesTriangle");
			parser.addOption<RectangularTriangle>("rt", "side1 side2", "Compute perimeter and area of a RectanglarTriangle");

			std::string errorMessage;
			const auto& options = parser.getOptions();
			
			// Valid shape, expect results
			int argc1 = 3;
			char* argv1[3] = { "ShapeCalculator.exe", "-c", "5." };
			Assert::IsTrue(parser.process(argc1, argv1, errorMessage));
			Assert::IsTrue(parser.getResults().compare("Circle(radius=5) has (perimeter=31.4159,area=78.5398).\n") == 0);
			
			//Invalid shape
			int argc2 = 3;
			char* argv2[3] = { "ShapeCalculator.exe", "-c", "-7.5" };
			Assert::IsTrue(parser.process(argc2, argv2, errorMessage));
			Assert::IsTrue(parser.getResults().compare("Circle(radius=-7.5) is invalid.\n") == 0);

			//Invalid arguments for the option
			int argc4 = 4;
			char* argv4[4] = { "ShapeCalculator.exe", "-c", "5.2", "4." };
			Assert::IsFalse(parser.process(argc4, argv4, errorMessage));
			Assert::IsTrue(errorMessage.compare("Error. Expecting the 3th parameter to be an option, not argument.") == 0);

			//Invalid argument type for the option
			int argc5 = 3;
			char* argv5[3] = { "ShapeCalculator.exe", "-c", "abc"};
			Assert::IsFalse(parser.process(argc5, argv5, errorMessage));
			Assert::IsTrue(errorMessage.compare(options.at("c")->getArgumentErrorMessage()) == 0);

			//Invalid number of arguments type for the option
			int argc6 = 3;
			char* argv6[3] = { "ShapeCalculator.exe", "-c", "-s" };
			Assert::IsFalse(parser.process(argc6, argv6, errorMessage));
			Assert::IsTrue(errorMessage.compare(options.at("c")->getArgumentErrorMessage()) == 0);

		}

		//Test the argument option '-d' for computing Donut shape
		TEST_METHOD(TestArgumentParser_DonutOption)
		{
			ArgumentParser parser;

			parser.addOption<Circle>("c", "radius", "Compute perimeter and area of a Circle");
			parser.addOption<Donut>("d", "internalRadius externalRadius", "Compute perimeter and area of a Donut");
			parser.addOption<Rectangle>("r", "width height", "Compute perimeter and area of a Rectangle");
			parser.addOption<Square>("s", "side", "Compute perimeter and area of a Square");
			parser.addOption<Triangle>("t", "side1 side2 side3", "Compute perimeter and area of a Triangle");
			parser.addOption<IsoscelesTriangle>("it", "side base", "Compute perimeter and area of a IsoscelesTriangle");
			parser.addOption<RectangularTriangle>("rt", "side1 side2", "Compute perimeter and area of a RectanglarTriangle");

			std::string errorMessage;
			const auto& options = parser.getOptions();
			
			// Valid shape, expect results
			int argc1 = 4;
			char* argv1[4] = { "ShapeCalculator.exe", "-d", "5.", "3." };
			Assert::IsTrue(parser.process(argc1, argv1, errorMessage));
			Assert::IsTrue(parser.getResults().compare("Donut(intern_radius=3,extern_radius=5) has (perimeter=50.2655,area=50.2655).\n") == 0);
			
			//Invalid shape
			int argc2 = 4;
			char* argv2[4] = { "ShapeCalculator.exe", "-d", "-7.5", "2." };
			Assert::IsTrue(parser.process(argc2, argv2, errorMessage));
			Assert::IsTrue(parser.getResults().compare("Donut(intern_radius=-7.5,extern_radius=2) is invalid.\n") == 0);
			
			//Invalid arguments for the option
			int argc4 = 5;
			char* argv4[5] = { "ShapeCalculator.exe", "-d", "5.2", "4.", "6."};
			Assert::IsFalse(parser.process(argc4, argv4, errorMessage));
			Assert::IsTrue(errorMessage.compare("Error. Expecting the 4th parameter to be an option, not argument.") == 0);

			//Invalid argument type for the option
			int argc5 = 4;
			char* argv5[4] = { "ShapeCalculator.exe", "-d", "7.", "abc" };
			Assert::IsFalse(parser.process(argc5, argv5, errorMessage));
			Assert::IsTrue(errorMessage.compare(options.at("d")->getArgumentErrorMessage()) == 0);

			//Invalid number of arguments type for the option
			int argc6 = 4;
			char* argv6[4] = { "ShapeCalculator.exe", "-d", "4", "-s" };
			Assert::IsFalse(parser.process(argc6, argv6, errorMessage));
			Assert::IsTrue(errorMessage.compare(options.at("d")->getArgumentErrorMessage()) == 0);
			
		}

		//Test the argument option '-s' for computing Square shape
		TEST_METHOD(TestArgumentParser_SquareOption)
		{
			ArgumentParser parser;

			parser.addOption<Circle>("c", "radius", "Compute perimeter and area of a Circle");
			parser.addOption<Donut>("d", "internalRadius externalRadius", "Compute perimeter and area of a Donut");
			parser.addOption<Rectangle>("r", "width height", "Compute perimeter and area of a Rectangle");
			parser.addOption<Square>("s", "side", "Compute perimeter and area of a Square");
			parser.addOption<Triangle>("t", "side1 side2 side3", "Compute perimeter and area of a Triangle");
			parser.addOption<IsoscelesTriangle>("it", "side base", "Compute perimeter and area of a IsoscelesTriangle");
			parser.addOption<RectangularTriangle>("rt", "side1 side2", "Compute perimeter and area of a RectanglarTriangle");

			std::string errorMessage;
			const auto& options = parser.getOptions();

			// Valid shape, expect results
			int argc1 = 3;
			char* argv1[3] = { "ShapeCalculator.exe", "-s", "5." };
			Assert::IsTrue(parser.process(argc1, argv1, errorMessage));
			Assert::IsTrue(parser.getResults().compare("Square(side=5) has (perimeter=20,area=25).\n") == 0);

			//Invalid shape
			int argc2 = 3;
			char* argv2[3] = { "ShapeCalculator.exe", "-s", "-7.5" };
			Assert::IsTrue(parser.process(argc2, argv2, errorMessage));
			Assert::IsTrue(parser.getResults().compare("Square(side=-7.5) is invalid.\n") == 0);

			//Invalid arguments for the option
			int argc4 = 4;
			char* argv4[4] = { "ShapeCalculator.exe", "-s", "5.2", "4." };
			Assert::IsFalse(parser.process(argc4, argv4, errorMessage));
			Assert::IsTrue(errorMessage.compare("Error. Expecting the 3th parameter to be an option, not argument.") == 0);

			//Invalid argument type for the option
			int argc5 = 3;
			char* argv5[3] = { "ShapeCalculator.exe", "-s", "abc" };
			Assert::IsFalse(parser.process(argc5, argv5, errorMessage));
			Assert::IsTrue(errorMessage.compare(options.at("s")->getArgumentErrorMessage()) == 0);

			//Invalid number of arguments type for the option
			int argc6 = 3;
			char* argv6[3] = { "ShapeCalculator.exe", "-s", "-r" };
			Assert::IsFalse(parser.process(argc6, argv6, errorMessage));
			Assert::IsTrue(errorMessage.compare(options.at("s")->getArgumentErrorMessage()) == 0);

		}

		//Test the argument option '-r' for computing Rectangle shape
		TEST_METHOD(TestArgumentParser_RectangleOption)
		{
			ArgumentParser parser;

			parser.addOption<Circle>("c", "radius", "Compute perimeter and area of a Circle");
			parser.addOption<Donut>("d", "internalRadius externalRadius", "Compute perimeter and area of a Donut");
			parser.addOption<Rectangle>("r", "width height", "Compute perimeter and area of a Rectangle");
			parser.addOption<Square>("s", "side", "Compute perimeter and area of a Square");
			parser.addOption<Triangle>("t", "side1 side2 side3", "Compute perimeter and area of a Triangle");
			parser.addOption<IsoscelesTriangle>("it", "side base", "Compute perimeter and area of a IsoscelesTriangle");
			parser.addOption<RectangularTriangle>("rt", "side1 side2", "Compute perimeter and area of a RectanglarTriangle");

			std::string errorMessage;
			const auto& options = parser.getOptions();

			// Valid shape, expect results
			int argc1 = 4;
			char* argv1[4] = { "ShapeCalculator.exe", "-r", "5.", "3." };
			Assert::IsTrue(parser.process(argc1, argv1, errorMessage));
			Assert::IsTrue(parser.getResults().compare("Rectangle(width=5,height=3) has (perimeter=16,area=15).\n") == 0);

			//Invalid shape
			int argc2 = 4;
			char* argv2[4] = { "ShapeCalculator.exe", "-r", "-7.5", "2." };
			Assert::IsTrue(parser.process(argc2, argv2, errorMessage));
			Assert::IsTrue(parser.getResults().compare("Rectangle(width=-7.5,height=2) is invalid.\n") == 0);

			//Invalid arguments for the option
			int argc4 = 5;
			char* argv4[5] = { "ShapeCalculator.exe", "-r", "5.2", "4.", "6." };
			Assert::IsFalse(parser.process(argc4, argv4, errorMessage));
			Assert::IsTrue(errorMessage.compare("Error. Expecting the 4th parameter to be an option, not argument.") == 0);

			//Invalid argument type for the option
			int argc5 = 4;
			char* argv5[4] = { "ShapeCalculator.exe", "-r", "7.", "abc" };
			Assert::IsFalse(parser.process(argc5, argv5, errorMessage));
			Assert::IsTrue(errorMessage.compare(options.at("r")->getArgumentErrorMessage()) == 0);

			//Invalid number of arguments type for the option
			int argc6 = 4;
			char* argv6[4] = { "ShapeCalculator.exe", "-r", "4", "-s" };
			Assert::IsFalse(parser.process(argc6, argv6, errorMessage));
			Assert::IsTrue(errorMessage.compare(options.at("r")->getArgumentErrorMessage()) == 0);

		}

		//Test the argument option '-rt' for computing Rectangular Triangle shape
		TEST_METHOD(TestArgumentParser_RectangularTriangleOption)
		{
			ArgumentParser parser;

			parser.addOption<Circle>("c", "radius", "Compute perimeter and area of a Circle");
			parser.addOption<Donut>("d", "internalRadius externalRadius", "Compute perimeter and area of a Donut");
			parser.addOption<Rectangle>("r", "width height", "Compute perimeter and area of a Rectangle");
			parser.addOption<Square>("s", "side", "Compute perimeter and area of a Square");
			parser.addOption<Triangle>("t", "side1 side2 side3", "Compute perimeter and area of a Triangle");
			parser.addOption<IsoscelesTriangle>("it", "side base", "Compute perimeter and area of a IsoscelesTriangle");
			parser.addOption<RectangularTriangle>("rt", "side1 side2", "Compute perimeter and area of a RectanglarTriangle");

			std::string errorMessage;
			const auto& options = parser.getOptions();
			
			// Valid shape, expect results
			int argc1 = 4;
			char* argv1[4] = { "ShapeCalculator.exe", "-rt", "4.", "3." };
			Assert::IsTrue(parser.process(argc1, argv1, errorMessage));
			Assert::IsTrue(parser.getResults().compare("RectangularTriangle(side1=4,side2=3) has (perimeter=12,area=6).\n") == 0);
			
			//Invalid shape
			int argc2 = 4;
			char* argv2[4] = { "ShapeCalculator.exe", "-rt", "-7.5", "2." };
			Assert::IsTrue(parser.process(argc2, argv2, errorMessage));
			Assert::IsTrue(parser.getResults().compare("RectangularTriangle(side1=-7.5,side2=2) is invalid.\n") == 0);
			
			//Invalid arguments for the option
			int argc4 = 5;
			char* argv4[5] = { "ShapeCalculator.exe", "-rt", "5.2", "4.", "6." };
			Assert::IsFalse(parser.process(argc4, argv4, errorMessage));
			Assert::IsTrue(errorMessage.compare("Error. Expecting the 4th parameter to be an option, not argument.") == 0);

			//Invalid argument type for the option
			int argc5 = 4;
			char* argv5[4] = { "ShapeCalculator.exe", "-rt", "7.", "abc" };
			Assert::IsFalse(parser.process(argc5, argv5, errorMessage));
			Assert::IsTrue(errorMessage.compare(options.at("rt")->getArgumentErrorMessage()) == 0);

			//Invalid number of arguments type for the option
			int argc6 = 4;
			char* argv6[4] = { "ShapeCalculator.exe", "-rt", "4", "-s" };
			Assert::IsFalse(parser.process(argc6, argv6, errorMessage));
			Assert::IsTrue(errorMessage.compare(options.at("rt")->getArgumentErrorMessage()) == 0);
			
		}


		//Test the argument option '-it' for computing Isosceles Triangle shape
		TEST_METHOD(TestArgumentParser_IsoscelesTriangleOption)
		{
			ArgumentParser parser;

			parser.addOption<Circle>("c", "radius", "Compute perimeter and area of a Circle");
			parser.addOption<Donut>("d", "internalRadius externalRadius", "Compute perimeter and area of a Donut");
			parser.addOption<Rectangle>("r", "width height", "Compute perimeter and area of a Rectangle");
			parser.addOption<Square>("s", "side", "Compute perimeter and area of a Square");
			parser.addOption<Triangle>("t", "side1 side2 side3", "Compute perimeter and area of a Triangle");
			parser.addOption<IsoscelesTriangle>("it", "side base", "Compute perimeter and area of a IsoscelesTriangle");
			parser.addOption<RectangularTriangle>("rt", "side1 side2", "Compute perimeter and area of a RectanglarTriangle");

			std::string errorMessage;
			const auto& options = parser.getOptions();

			// Valid shape, expect results
			int argc1 = 4;
			char* argv1[4] = { "ShapeCalculator.exe", "-it", "5.", "6." };
			Assert::IsTrue(parser.process(argc1, argv1, errorMessage));
			Assert::IsTrue(parser.getResults().compare("IsoscelesTriangle(side=5,base=6) has (perimeter=16,area=12).\n") == 0);
			
			//Invalid shape
			int argc2 = 4;
			char* argv2[4] = { "ShapeCalculator.exe", "-it", "5.", "11." };
			Assert::IsTrue(parser.process(argc2, argv2, errorMessage));
			Assert::IsTrue(parser.getResults().compare("IsoscelesTriangle(side=5,base=11) is invalid.\n") == 0);
			
			//Invalid arguments for the option
			int argc4 = 5;
			char* argv4[5] = { "ShapeCalculator.exe", "-it", "5.2", "4.", "6." };
			Assert::IsFalse(parser.process(argc4, argv4, errorMessage));
			Assert::IsTrue(errorMessage.compare("Error. Expecting the 4th parameter to be an option, not argument.") == 0);

			//Invalid argument type for the option
			int argc5 = 4;
			char* argv5[4] = { "ShapeCalculator.exe", "-it", "7.", "abc" };
			Assert::IsFalse(parser.process(argc5, argv5, errorMessage));
			Assert::IsTrue(errorMessage.compare(options.at("it")->getArgumentErrorMessage()) == 0);

			//Invalid number of arguments type for the option
			int argc6 = 4;
			char* argv6[4] = { "ShapeCalculator.exe", "-it", "4", "-s" };
			Assert::IsFalse(parser.process(argc6, argv6, errorMessage));
			Assert::IsTrue(errorMessage.compare(options.at("it")->getArgumentErrorMessage()) == 0);
			
		}


		//Test the argument option '-t' for computing Triangle shape
		TEST_METHOD(TestArgumentParser_TriangleOption)
		{
			ArgumentParser parser;

			parser.addOption<Circle>("c", "radius", "Compute perimeter and area of a Circle");
			parser.addOption<Donut>("d", "internalRadius externalRadius", "Compute perimeter and area of a Donut");
			parser.addOption<Rectangle>("r", "width height", "Compute perimeter and area of a Rectangle");
			parser.addOption<Square>("s", "side", "Compute perimeter and area of a Square");
			parser.addOption<Triangle>("t", "side1 side2 side3", "Compute perimeter and area of a Triangle");
			parser.addOption<IsoscelesTriangle>("it", "side base", "Compute perimeter and area of a IsoscelesTriangle");
			parser.addOption<RectangularTriangle>("rt", "side1 side2", "Compute perimeter and area of a RectanglarTriangle");

			std::string errorMessage;
			const auto& options = parser.getOptions();
			
			// Valid shape, expect results
			int argc1 = 5;
			char* argv1[5] = { "ShapeCalculator.exe", "-t", "3.", "4." , "5." };
			Assert::IsTrue(parser.process(argc1, argv1, errorMessage));
			Assert::IsTrue(parser.getResults().compare("Triangle(side1=3,side2=4,side3=5) has (perimeter=12,area=6).\n") == 0);
			
			//Invalid shape
			int argc2 = 5;
			char* argv2[5] = { "ShapeCalculator.exe", "-t", "3.", "6.", "2" };
			Assert::IsTrue(parser.process(argc2, argv2, errorMessage));
			Assert::IsTrue(parser.getResults().compare("Triangle(side1=3,side2=6,side3=2) is invalid.\n") == 0);
			
			//Invalid arguments for the option
			int argc4 = 6;
			char* argv4[6] = { "ShapeCalculator.exe", "-t", "5.2", "4.", "6.", "7.5" };
			Assert::IsFalse(parser.process(argc4, argv4, errorMessage));
			Assert::IsTrue(errorMessage.compare("Error. Expecting the 5th parameter to be an option, not argument.") == 0);
			
			//Invalid argument type for the option
			int argc5 = 5;
			char* argv5[5] = { "ShapeCalculator.exe", "-t", "7.", "abc", "3." };
			Assert::IsFalse(parser.process(argc5, argv5, errorMessage));
			Assert::IsTrue(errorMessage.compare(options.at("t")->getArgumentErrorMessage()) == 0);
			
			//Invalid number of arguments type for the option
			int argc6 = 4;
			char* argv6[4] = { "ShapeCalculator.exe", "-t", "4", "5"};
			Assert::IsFalse(parser.process(argc6, argv6, errorMessage));
			Assert::IsTrue(errorMessage.compare(options.at("t")->getArgumentErrorMessage()) == 0);
			
		}


		//Test the use of two options
		TEST_METHOD(TestArgumentParser_TwoOption)
		{
			ArgumentParser parser;
			
			parser.addOption<Circle>("c", "radius", "Compute perimeter and area of a Circle");
			parser.addOption<Donut>("d", "internalRadius externalRadius", "Compute perimeter and area of a Donut");
			parser.addOption<Rectangle>("r", "width height", "Compute perimeter and area of a Rectangle");
			parser.addOption<Square>("s", "side", "Compute perimeter and area of a Square");
			parser.addOption<Triangle>("t", "side1 side2 side3", "Compute perimeter and area of a Triangle");
			parser.addOption<IsoscelesTriangle>("it", "side base", "Compute perimeter and area of a IsoscelesTriangle");
			parser.addOption<RectangularTriangle>("rt", "side1 side2", "Compute perimeter and area of a RectanglarTriangle");

			std::string errorMessage;
			const auto& options = parser.getOptions();

			// Valid shape, expect results
			int argc1 = 7;
			char* argv1[7] = { "ShapeCalculator.exe", "-t", "3.", "4." , "5." , "-s", "2.5" };
			Assert::IsTrue(parser.process(argc1, argv1, errorMessage));
			std::string expected = "Triangle(side1=3,side2=4,side3=5) has (perimeter=12,area=6).\n";
			expected += "Square(side=2.5) has (perimeter=10,area=6.25).\n";
			Assert::IsTrue(parser.getResults() == expected);


			// The rectangle is valid, the square is invalid
			int argc2 = 6;
			char* argv2[6] = { "ShapeCalculator.exe", "-r", "3.", "4.", "-s", "-2.5" };
			Assert::IsTrue(parser.process(argc2, argv2, errorMessage));
			expected = "Rectangle(width=3,height=4) has (perimeter=14,area=12).\n";
			expected += "Square(side=-2.5) is invalid.\n";
			Assert::IsTrue(parser.getResults() == expected);

		}
	};
}