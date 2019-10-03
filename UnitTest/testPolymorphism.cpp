#include "stdafx.h"
#include "CppUnitTest.h"
#include "Square.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Donut.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTestPolymorphism)
	{
	public:

		TEST_METHOD(TestPolymorphism_Downcasting)
		{
			Square c(4.);
			
			RectangleShape* rs = &c;
			
			// Downcasting from RectangleShape* to Square*
			Square* c_pointer = rs->getPointer<Square>();
			Assert::AreEqual(4., c_pointer->getSide());

			// Downcasting from RectangleShape* to Rectangle*
			Rectangle* r_pointer = rs->getPointer<Rectangle>();
			Assert::IsTrue(r_pointer == nullptr);

			Shape2D* s2D = &c;

			// Downcasting from Shape2D* to Square*
			Square* c_ptr = s2D->getPointer<Square>();
			Assert::AreEqual(4., c_ptr->getSide());

			// Downcasting from Shape2D* to Triangle*
			Triangle* tri_ptr = s2D->getPointer<Triangle>();
			Assert::IsTrue(tri_ptr == nullptr);

			Shape* s = &c;
			
			// Downcasting from Shape* to Square*
			Square* c_ptr1 = s->getPointer<Square>();
			Assert::AreEqual(4., c_ptr1->getSide());

			// Downcasting from Shape* to Donut*
			Donut* d_ptr = s->getPointer<Donut>();
			Assert::IsTrue(d_ptr == nullptr);


		}

	};
}