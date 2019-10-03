#include "stdafx.h"
#include "CppUnitTest.h"
#include "Square.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTestSquare)
	{
	public:

		//Test empty constructor
		TEST_METHOD(TestSquare_Constructor0)
		{
			Square rec;
			Assert::AreEqual(0., rec.getSide());
		}

		//Test constructor with 1 argument
		TEST_METHOD(TestSquare_Constructor1)
		{
			Square rec(2.);
			Assert::AreEqual(2., rec.getSide());
		}

		TEST_METHOD(TestSquare_setDimension)
		{
			Square rec;
			rec.setDimension(2.);
			Assert::AreEqual(2., rec.getSide());
		}

		TEST_METHOD(TestSquare_getSide)
		{
			Square rec(2.);
			Assert::AreEqual(2., rec.getSide());
		}

		TEST_METHOD(TestSquare_getClassShapeName)
		{
			Assert::IsTrue(Square::getClassShapeName() == "Square");
		}


		TEST_METHOD(TestSquare_getSerializationSize)
		{
			Square rec;
			Assert::IsTrue(rec.getSerializationSize() == 1);
		}

		// Test setDimension(const std::vector<double>&)
		TEST_METHOD(TestSquare_setDimension_vector)
		{
			Square rec;
			std::vector<double> v1;
			rec.setDimension(v1);
			Assert::AreEqual(0., rec.getSide());

			std::vector<double> v2 = { 2.5 };
			rec.setDimension(v2);
			Assert::AreEqual(2.5, rec.getSide());
			
			std::vector<double> v3 = { 3., 6.8 };
			rec.setDimension(v3);
			Assert::AreEqual(3., rec.getSide());
		}

		TEST_METHOD(TestSquare_getShapeName)
		{
			Square rec;
			Assert::IsTrue(rec.getShapeName() == "Square");
		}

		TEST_METHOD(TestSquare_GetPerimeter)
		{
			// Expect the perimeter to be zero for zero side length.
			Square z0;
			Assert::AreEqual(0., z0.getPerimeter());
			Square z1(0.);
			Assert::AreEqual(0., z1.getPerimeter());
			
			// Expect the perimeter to be zero for negative side length.
			Square n1(-4.2);
			Assert::AreEqual(0., n1.getPerimeter());
			
			// Expect perimeter to be 4 * side for positive side length.
			Square rec(3.);
			double expected = 12.;
			Assert::AreEqual(expected, rec.getPerimeter());

		}

		TEST_METHOD(TestSquare_GetArea)
		{
			// Expect the area to be zero for zero side length.
			Square z0;
			Assert::AreEqual(0., z0.getArea());
			Square z1(0.);
			Assert::AreEqual(0., z1.getArea());
			
			// Expect the area to be zero for negative side length.
			Square n1(-4.2);
			Assert::AreEqual(0., n1.getArea());
			
			// Expect area to be side * side for positive side length.
			Square rec(3.);
			double expected = 9.;
			Assert::AreEqual(expected, rec.getArea());

		}

		TEST_METHOD(TestSquare_IsValid)
		{
			// Expect false for zero side length.
			Square z0;
			Assert::IsFalse(z0.isValid());
			Square z1(0.);
			Assert::IsFalse(z1.isValid());
			
			// Expect false for negative side length.
			Square n1(-4.2);
			Assert::IsFalse(n1.isValid());
			
			// Expect true for positive side length.
			Square rec(3.);
			Assert::IsTrue(rec.isValid());

		}

		TEST_METHOD(TestSquare_getInfoString) {
			double side = 5.5;
			Square rec(side);
			std::string expected("Square(side=5.5)");
			Assert::AreEqual(expected, rec.getInfoString());
		}
	};
}