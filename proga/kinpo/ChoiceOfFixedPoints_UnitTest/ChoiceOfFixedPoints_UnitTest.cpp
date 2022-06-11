#include "pch.h"
#include "CppUnitTest.h"
#include "../kinpo/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ChoiceOfFixedPointsUnitTest
{
	TEST_CLASS(ChoiceOfFixedPointsUnitTest)
	{
	public:
		TEST_METHOD(TypeTest)
		{
			int amountOfNumber = 6;
			int numberOfFixedPoints = 5;

			int result = choiceOfFixedPoints(amountOfNumber, numberOfFixedPoints);
			int expResult = 6;

			Assert::AreEqual(expResult, result);
		};

		TEST_METHOD(OneArgumentGreaterThanTheOther)
		{
			int amountOfNumber = 5;
			int numberOfFixedPoints = 9;

			int result = choiceOfFixedPoints(amountOfNumber, numberOfFixedPoints);
			int expResult = -1;

			Assert::AreEqual(expResult, result);
		};

		TEST_METHOD(OneArgumentIsZero)
		{
			int amountOfNumber = 5;
			int numberOfFixedPoints = 0;

			int result = choiceOfFixedPoints(amountOfNumber, numberOfFixedPoints);
			int expResult = 1;

			Assert::AreEqual(expResult, result);
		};

		TEST_METHOD(TwoArgumentsAreZero)
		{
			int amountOfNumber = 0;
			int numberOfFixedPoints = 0;

			int result = choiceOfFixedPoints(amountOfNumber, numberOfFixedPoints);
			int expResult = 1;

			Assert::AreEqual(expResult, result);
		};

		TEST_METHOD(complexTest)
		{
			int amountOfNumber = 6;
			int numberOfFixedPoints = 4;

			int result = choiceOfFixedPoints(amountOfNumber, numberOfFixedPoints);
			int expResult = 15;

			Assert::AreEqual(expResult, result);
		};

		TEST_METHOD(TwoArgumentsAreSame)
		{
			int amountOfNumber = 5;
			int numberOfFixedPoints = 5;

			int result = choiceOfFixedPoints(amountOfNumber, numberOfFixedPoints);
			int expResult = 1;

			Assert::AreEqual(expResult, result);
		};
	}; 
}
