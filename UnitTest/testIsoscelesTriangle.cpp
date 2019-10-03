#include "stdafx.h"
#include "CppUnitTest.h"
#include "IsoscelesTriangle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTestIsoscelesTriangle)
	{
	public:

		//Test empty constructor
		TEST_METHOD(TestIsoscelesTriangle_Constructor0)
		{
			IsoscelesTriangle tri;
			Assert::AreEqual(0., tri.getSide());
			Assert::AreEqual(0., tri.getBase());
		}

		//Test constructor with 2 arguments
		TEST_METHOD(TestIsoscelesTriangle_Constructor2)
		{
			IsoscelesTriangle tri(2., 3.);
			Assert::AreEqual(2., tri.getSide());
			Assert::AreEqual(3., tri.getBase());
		}

		TEST_METHOD(TestIsoscelesTriangle_setDimension)
		{
			IsoscelesTriangle tri;
			tri.setDimension(2., 3.);
			Assert::AreEqual(2., tri.getSide());
			Assert::AreEqual(3., tri.getBase());
		}

		TEST_METHOD(TestIsoscelesTriangle_GetSide)
		{
			IsoscelesTriangle tri(2., 3.);
			Assert::AreEqual(2., tri.getSide());
		}

		TEST_METHOD(TestIsoscelesTriangle_GetBase)
		{
			IsoscelesTriangle tri(2., 3.);
			Assert::AreEqual(3., tri.getBase());
		}

		TEST_METHOD(TestIsoscelesTriangle_getClassShapeName)
		{
			Assert::IsTrue(IsoscelesTriangle::getClassShapeName() == "IsoscelesTriangle");
		}

		TEST_METHOD(TestIsoscelesTriangle_getSerializationSize)
		{
			IsoscelesTriangle tri;
			Assert::IsTrue(tri.getSerializationSize() == 2);
		}

		// Test setDimension(const std::vector<double>&)
		TEST_METHOD(TestIsoscelesTriangle_setDimension_vector)
		{
			IsoscelesTriangle tri;
			std::vector<double> v1;
			tri.setDimension(v1);
			Assert::AreEqual(0., tri.getSide());
			Assert::AreEqual(0., tri.getBase());

			std::vector<double> v2 = { 2.5 };
			tri.setDimension(v2);
			Assert::AreEqual(2.5, tri.getSide());
			Assert::AreEqual(0., tri.getBase());

			std::vector<double> v3 = { 3., 2.5 };
			tri.setDimension(v3);
			Assert::AreEqual(3., tri.getSide());
			Assert::AreEqual(2.5, tri.getBase());

			std::vector<double> v4 = { 7.4, 3., 2.5 };
			tri.setDimension(v4);
			Assert::AreEqual(7.4, tri.getSide());
			Assert::AreEqual(3., tri.getBase());

		}

		TEST_METHOD(TestIsoscelesTriangle_getShapeName)
		{
			IsoscelesTriangle tri;
			Assert::IsTrue(tri.getShapeName() == "IsoscelesTriangle");
		}

		TEST_METHOD(TestIsoscelesTriangle_GetPerimeter)
		{
			// Expect the perimeter to be zero for zero base length or zero side length
			IsoscelesTriangle z0;
			Assert::AreEqual(0., z0.getPerimeter());
			IsoscelesTriangle z1(0., 2.);
			Assert::AreEqual(0., z1.getPerimeter());
			IsoscelesTriangle z2(2., 0.);
			Assert::AreEqual(0., z2.getPerimeter());

			// Expect the perimeter to be zero for negative base length or negative side length
			IsoscelesTriangle n1(-4.2, 3);
			Assert::AreEqual(0., n1.getPerimeter());
			IsoscelesTriangle n2(4.2, -3);
			Assert::AreEqual(0., n2.getPerimeter());
			IsoscelesTriangle n3(-4.2, -3);
			Assert::AreEqual(0., n3.getPerimeter());

			// Expected the perimeter to be zero for triangles where 2 * side <= base
			IsoscelesTriangle c1(2., 5.);
			Assert::AreEqual(0., c1.getPerimeter());
			IsoscelesTriangle c2(2., 4.);
			Assert::AreEqual(0., c2.getPerimeter());

			// Expect the perimeter to be 2 * side + base for positive side and base, and 2 * side > base
			IsoscelesTriangle tri(2., 3.);
			double expected = 7.;
			Assert::AreEqual(expected, tri.getPerimeter());

		}

		TEST_METHOD(TestIsoscelesTriangle_GetArea)
		{
			// Expect the area to be zero for zero base length or zero side length
			IsoscelesTriangle z0;
			Assert::AreEqual(0., z0.getArea());
			IsoscelesTriangle z1(0., 2.);
			Assert::AreEqual(0., z1.getArea());
			IsoscelesTriangle z2(2., 0.);
			Assert::AreEqual(0., z2.getArea());

			// Expect the area to be zero for negative base length or negative side length
			IsoscelesTriangle n1(-4.2, 3);
			Assert::AreEqual(0., n1.getArea());
			IsoscelesTriangle n2(4.2, -3);
			Assert::AreEqual(0., n2.getArea());
			IsoscelesTriangle n3(-4.2, -3);
			Assert::AreEqual(0., n3.getArea());

			// Expected the area to be zero for triangles where 2 * side <= base
			IsoscelesTriangle c1(2., 5.);
			Assert::AreEqual(0., c1.getArea());
			IsoscelesTriangle c2(2., 4.);
			Assert::AreEqual(0., c2.getArea());

			// Expect positive area for positive side and base, and 2 * side > base
			IsoscelesTriangle tri(5., 6.);
			double expected = 12.;
			Assert::AreEqual(expected, tri.getArea());

		}

		TEST_METHOD(TestIsoscelesTriangle_IsValid)
		{
			// Expect false for zero base length or zero side length
			IsoscelesTriangle z0;
			Assert::IsFalse(z0.isValid());
			IsoscelesTriangle z1(0., 2.);
			Assert::IsFalse(z1.isValid());
			IsoscelesTriangle z2(2., 0.);
			Assert::IsFalse(z2.isValid());

			// Expect false for negative base length or negative side length
			IsoscelesTriangle n1(-4.2, 3);
			Assert::IsFalse(n1.isValid());
			IsoscelesTriangle n2(4.2, -3);
			Assert::IsFalse(n2.isValid());
			IsoscelesTriangle n3(-4.2, -3);
			Assert::IsFalse(n3.isValid());

			// Expected false for triangles where 2 * side <= base
			IsoscelesTriangle c1(2., 5.);
			Assert::IsFalse(c1.isValid());
			IsoscelesTriangle c2(2., 4.);
			Assert::IsFalse(c2.isValid());

			// Expect true for triangles with positive base and side and 2 * side > base
			IsoscelesTriangle tri(5., 6.);
			Assert::IsTrue(tri.isValid());
		}

		TEST_METHOD(TestIsoscelesTriangle_getInfoString) {
			double side = 5;
			double base = 6;
			IsoscelesTriangle tri(side, base);
			std::string expected("IsoscelesTriangle(side=5,base=6)");
			Assert::AreEqual(expected, tri.getInfoString());
		}
	};
}