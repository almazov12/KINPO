#include "pch.h"
#include "CppUnitTest.h"
#include "../kinpo/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace numberOfTranspositionWithoutFixedPointsUnitTest
{
	TEST_CLASS(numberOfTranspositionWithoutFixedPointsUnitTest)
	{
	public:
		
		TEST_METHOD(TypeTest)
		{
			int amountOfNumber = 2;

			int result = numberOfTranspositionWithoutFixedPoints(amountOfNumber);
			int expResult = 1;

			Assert::AreEqual(expResult, result);
		};

		TEST_METHOD(IncorrectAmountOfNumbers)
		{
			int amountOfNumber = 0;

			int result = numberOfTranspositionWithoutFixedPoints(amountOfNumber);
			int expResult = -1;

			Assert::AreEqual(expResult, result);
		};

		TEST_METHOD(complexTest)
		{
			int amountOfNumber = 5;

			int result = numberOfTranspositionWithoutFixedPoints(amountOfNumber);
			int expResult = 44; //???

			Assert::AreEqual(expResult, result);
		};

		TEST_METHOD(IncorrectAmountOfNumbers1)
		{
			int amountOfNumber = -2;

			int result = numberOfTranspositionWithoutFixedPoints(amountOfNumber);
			int expResult = -1;

			Assert::AreEqual(expResult, result);
		}
	};
}
