#include "stdafx.h"
#include "CppUnitTest.h"
#include "RectangularTriangle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTestRectangularTriangle)
	{
	public:

		//Test empty constructor
		TEST_METHOD(TestRectangularTriangle_Constructor0)
		{
			RectangularTriangle rec;
			Assert::AreEqual(0., rec.getFirstSide());
			Assert::AreEqual(0., rec.getSecondSide());
		}

		//Test constructor with 2 arguments
		TEST_METHOD(TestRectangularTriangle_Constructor2)
		{
			RectangularTriangle rec(2., 3.);
			Assert::AreEqual(2., rec.getFirstSide());
			Assert::AreEqual(3., rec.getSecondSide());
		}

		TEST_METHOD(TestRectangularTriangle_setDimension)
		{
			RectangularTriangle rec;
			rec.setDimension(2., 3.);
			Assert::AreEqual(2., rec.getFirstSide());
			Assert::AreEqual(3., rec.getSecondSide());
		}

		TEST_METHOD(TestRectangularTriangle_GetFirstSide)
		{
			RectangularTriangle rec(2., 3.);
			Assert::AreEqual(2., rec.getFirstSide());
		}

		TEST_METHOD(TestRectangularTriangle_GetSecondSide)
		{
			RectangularTriangle rec(2., 3.);
			Assert::AreEqual(3., rec.getSecondSide());
		}

		TEST_METHOD(TestRectangularTriangle_getClassShapeName)
		{
			Assert::IsTrue(RectangularTriangle::getClassShapeName() == "RectangularTriangle");
		}

		TEST_METHOD(TestRectangularTriangle_getSerializationSize)
		{
			RectangularTriangle tri;
			Assert::IsTrue(tri.getSerializationSize() == 2);
		}

		// Test setDimension(const std::vector<double>&)
		TEST_METHOD(TestRectangularTriangle_setDimension_vector)
		{
			RectangularTriangle tri;
			std::vector<double> v1;
			tri.setDimension(v1);
			Assert::AreEqual(0., tri.getFirstSide());
			Assert::AreEqual(0., tri.getSecondSide());

			std::vector<double> v2 = { 2.5 };
			tri.setDimension(v2);
			Assert::AreEqual(2.5, tri.getFirstSide());
			Assert::AreEqual(0., tri.getSecondSide());

			std::vector<double> v3 = { 3., 2.5 };
			tri.setDimension(v3);
			Assert::AreEqual(3., tri.getFirstSide());
			Assert::AreEqual(2.5, tri.getSecondSide());

			std::vector<double> v4 = { 7.4, 3., 2.5 };
			tri.setDimension(v4);
			Assert::AreEqual(7.4, tri.getFirstSide());
			Assert::AreEqual(3., tri.getSecondSide());

		}

		TEST_METHOD(TestRectangularTriangle_getShapeName)
		{
			RectangularTriangle rec;
			Assert::IsTrue(rec.getShapeName() == "RectangularTriangle");
		}

		TEST_METHOD(TestRectangularTriangle_GetPerimeter)
		{
			// Expect the perimeter to be zero if one of the side lengths is zero.
			RectangularTriangle z0;
			Assert::AreEqual(0., z0.getPerimeter());
			RectangularTriangle z1(0., 2.);
			Assert::AreEqual(0., z1.getPerimeter());
			RectangularTriangle z2(2., 0.);
			Assert::AreEqual(0., z2.getPerimeter());

			// Expect the perimeter to be zero if one of the side lengths is negative.
			RectangularTriangle n1(-4.2, 3);
			Assert::AreEqual(0., n1.getPerimeter());
			RectangularTriangle n2(4.2, -3);
			Assert::AreEqual(0., n2.getPerimeter());
			RectangularTriangle n3(-4.2, -3);
			Assert::AreEqual(0., n3.getPerimeter());

			// Expect positive perimeter for positive side lengths
			RectangularTriangle rec(3., 4.);
			double expected = 12.;
			Assert::AreEqual(expected, rec.getPerimeter());

		}

		TEST_METHOD(TestRectangularTriangle_GetArea)
		{
			// Expect the area to be zero if one of the side lengths is zero.
			RectangularTriangle z0;
			Assert::AreEqual(0., z0.getArea());
			RectangularTriangle z1(0., 2.);
			Assert::AreEqual(0., z1.getArea());
			RectangularTriangle z2(2., 0.);
			Assert::AreEqual(0., z2.getArea());

			// Expect the area to be zero if one of the side lengths is negative.
			RectangularTriangle n1(-4.2, 3);
			Assert::AreEqual(0., n1.getArea());
			RectangularTriangle n2(4.2, -3);
			Assert::AreEqual(0., n2.getArea());
			RectangularTriangle n3(-4.2, -3);
			Assert::AreEqual(0., n3.getArea());

			// Expect positive area for positive side lengths
			RectangularTriangle rec(3., 4.);
			double expected = 6.;
			Assert::AreEqual(expected, rec.getArea());

		}

		TEST_METHOD(TestRectangularTriangle_IsValid)
		{
			// Expect false if one of the side lengths is zero.
			RectangularTriangle z0;
			Assert::IsFalse(z0.isValid());
			RectangularTriangle z1(0., 2.);
			Assert::IsFalse(z1.isValid());
			RectangularTriangle z2(2., 0.);
			Assert::IsFalse(z2.isValid());

			// Expect false if one of the side lengths is negative.
			RectangularTriangle n1(-4.2, 3);
			Assert::IsFalse(n1.isValid());
			RectangularTriangle n2(4.2, -3);
			Assert::IsFalse(n2.isValid());
			RectangularTriangle n3(-4.2, -3);
			Assert::IsFalse(n3.isValid());

			// Expect true for positive side lengths
			RectangularTriangle rec(3., 4.);
			Assert::IsTrue(rec.isValid());

		}

		TEST_METHOD(TestRectangularTriangle_getInfoString) {
			double side1 = 5;
			double side2 = 6;
			RectangularTriangle tri(side1, side2);
			std::string expected("RectangularTriangle(side1=5,side2=6)");
			Assert::AreEqual(expected, tri.getInfoString());
		}
	};
}