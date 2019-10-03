#include "stdafx.h"
#include "CppUnitTest.h"
#include "Donut.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTestDonut)
	{
	public:

		//Test empty constructor
		TEST_METHOD(TestDonut_Constructor0)
		{
			
			Donut d;
			Assert::AreEqual(0., d.getInternalRadius());
			Assert::AreEqual(0., d.getExternalRadius());
		}

		//Test constructor with 2 arguments
		TEST_METHOD(TestDonut_Constructor2)
		{
			Donut d1(2., 3.);
			Assert::AreEqual(2., d1.getInternalRadius());
			Assert::AreEqual(3., d1.getExternalRadius());

			// Check if the internal and external radius are still correct after switching their order in the constructor
			Donut d2(3., 2.);
			Assert::AreEqual(2., d1.getInternalRadius());
			Assert::AreEqual(3., d1.getExternalRadius());

		}

		TEST_METHOD(TestDonut_setDimension)
		{
			Donut d;
			d.setDimension(2., 3.);
			Assert::AreEqual(2., d.getInternalRadius());
			Assert::AreEqual(3., d.getExternalRadius());

			// Check if the internal and external radius are still correct after switching their order in the constructor
			d.setDimension(3., 2.);
			Assert::AreEqual(2., d.getInternalRadius());
			Assert::AreEqual(3., d.getExternalRadius());

		}

		TEST_METHOD(TestDonut_GetInternalRadius)
		{
			Donut d1(4., 5.);
			Assert::AreEqual(4., d1.getInternalRadius());

			Donut d2(5., 4.);
			Assert::AreEqual(4., d2.getInternalRadius());
		}

		TEST_METHOD(TestDonut_GetExternalRadius)
		{
			Donut d1(4., 5.);
			Assert::AreEqual(5., d1.getExternalRadius());

			Donut d2(5., 4.);
			Assert::AreEqual(5., d2.getExternalRadius());
		}

		TEST_METHOD(TestDonut_getClassShapeName)
		{
			Assert::IsTrue(Donut::getClassShapeName() == "Donut");
		}


		TEST_METHOD(TestDonut_getSerializationSize)
		{
			Donut d;
			Assert::IsTrue(d.getSerializationSize() == 2);
		}

		// Test setDimension(const std::vector<double>&)
		TEST_METHOD(TestDonut_setDimension_vector)
		{
			Donut d;
			std::vector<double> v1;
			d.setDimension(v1);
			Assert::AreEqual(0., d.getInternalRadius());
			Assert::AreEqual(0., d.getExternalRadius());

			std::vector<double> v2 = { 2.5 };
			d.setDimension(v2);
			Assert::AreEqual(0., d.getInternalRadius());
			Assert::AreEqual(2.5, d.getExternalRadius());

			std::vector<double> v3 = { 3., 2.5 };
			d.setDimension(v3);
			Assert::AreEqual(2.5, d.getInternalRadius());
			Assert::AreEqual(3., d.getExternalRadius());

			std::vector<double> v4 = { 7.4, 3., 2.5 };
			d.setDimension(v4);
			Assert::AreEqual(3., d.getInternalRadius());
			Assert::AreEqual(7.4, d.getExternalRadius());

		}

		TEST_METHOD(TestDonut_getShapeName)
		{
			Donut c;
			Assert::IsTrue(c.getShapeName() == "Donut");
		}

		TEST_METHOD(TestDonut_GetPerimeter)
		{
			// Expect the perimeter to be zero if one of the radii is zero.
			Donut z1;
			Assert::AreEqual(0., z1.getPerimeter());
			Donut z2(3., 0.);
			Assert::AreEqual(0., z2.getPerimeter());
			Donut z3(0., 3);
			Assert::AreEqual(0., z3.getPerimeter());
			Donut z4(0., 0.);
			Assert::AreEqual(0., z4.getPerimeter());

			// Expect the perimeter to be zero if one of the radii is negative.
			Donut n1(-4., 3.);
			Assert::AreEqual(0., n1.getPerimeter());
			Donut n2(3., -4.);
			Assert::AreEqual(0., n2.getPerimeter());
			Donut n3(-4., -3.);
			Assert::AreEqual(0., n3.getPerimeter());

			// Expect the perimeter to be zero if the internal and external radii are equal to each other.
			Donut e1(3., 3.);
			Assert::AreEqual(0., e1.getPerimeter());

			// Expect the perimeter to be the sum of the internal and external perimeters 
			// if the internal radius ri and external radius re are positive and not equal to each other.
			double ri = 3.5, re = 5.5;
			Donut d(ri, re);
			double expected = ri * M_PI * 2 + re * M_PI * 2;
			Assert::AreEqual(expected, d.getPerimeter(), std::numeric_limits<double>::epsilon());
		}

		TEST_METHOD(TestDonut_GetArea)
		{
			// Expect the area to be zero if one of the radii is zero
			Donut z1;
			Assert::AreEqual(0., z1.getArea());
			Donut z2(3., 0.);
			Assert::AreEqual(0., z2.getArea());
			Donut z3(0., 3);
			Assert::AreEqual(0., z3.getArea());
			Donut z4(0., 0.);
			Assert::AreEqual(0., z4.getArea());

			// Expect the area to be zero if one of the radii is negative
			Donut n1(-4., 3.);
			Assert::AreEqual(0., n1.getArea());
			Donut n2(3., -4.);
			Assert::AreEqual(0., n2.getArea());
			Donut n3(-4., -3.);
			Assert::AreEqual(0., n3.getArea());

			// Expect the area to be zero if the internal and external radii are equal to each other
			Donut e1(3., 3.);
			Assert::AreEqual(0., e1.getArea());

			// Expect the area to be the difference between the external and internal areas 
			// if the internal radius ri and external radius re 
			// are positive and not equal to each other.
			double ri = 3.5, re = 5.5;
			double expected = re * re * M_PI - ri * ri * M_PI;
			Donut d(ri, re);
			Assert::AreEqual(expected, d.getArea());
		}

		TEST_METHOD(TestDonut_IsValid)
		{
			// Expect false for if one of the radii is zero
			Donut z1;
			Assert::IsFalse(z1.isValid());
			Donut z2(3., 0.);
			Assert::IsFalse(z2.isValid());
			Donut z3(0., 3);
			Assert::IsFalse(z3.isValid());
			Donut z4(0., 0.);
			Assert::IsFalse(z4.isValid());

			// Expect false if one of the radii is negative
			Donut n1(-4., 3.);
			Assert::IsFalse(n1.isValid());
			Donut n2(3., -4.);
			Assert::IsFalse(n2.isValid());
			Donut n3(-4., -3.);
			Assert::IsFalse(n3.isValid());

			// Expect false if the internal and external radii are equal to each other
			Donut e1(3., 3.);
			Assert::IsFalse(e1.isValid());

			// Expect true if the internal and external radii are positive and not equal to each other.
			double ri = 3.5, re = 5.5;
			Donut d(ri, re);
			Assert::IsTrue(d.isValid());
		}


		TEST_METHOD(TestDonut_getInfoString) {
			double radius1 = 5.5;
			double radius2 = 3.5;
			Donut d(radius1, radius2);
			std::string expected("Donut(intern_radius=3.5,extern_radius=5.5)");
			Assert::AreEqual(expected, d.getInfoString());
		}
	};
}