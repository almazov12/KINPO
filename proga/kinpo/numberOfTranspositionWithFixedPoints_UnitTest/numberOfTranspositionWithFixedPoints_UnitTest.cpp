#include "pch.h"
#include "CppUnitTest.h"
#include "../kinpo/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace numberOfTranspositionWithFixedPointsUnitTest
{
	TEST_CLASS(numberOfTranspositionWithFixedPointsUnitTest)
	{
	public:
		TEST_METHOD(TypeTest)
		{
			int amountOfNumber = 4;
			int numberOfFixedPoints = 3;

			int result = numberOfTranspositionWithFixedPoints(amountOfNumber, numberOfFixedPoints);
			int expResult = 0;

			Assert::AreEqual(expResult, result);
		};
		
		TEST_METHOD(IncorrectInput)
		{
			int amountOfNumber = -6;
			int numberOfFixedPoints = -5;

			int result = numberOfTranspositionWithFixedPoints(amountOfNumber, numberOfFixedPoints);
			int expResult = -1;

			Assert::AreEqual(expResult, result);
		};


	};
}
