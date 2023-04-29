#include "pch.h"
#include "CppUnitTest.h"
#include "../kinpo/functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace splitFractionTests
{
	TEST_CLASS(splitFractionTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string roman = "X/II",
				romanNumerator = {},
				romanDenominator = {},
				expNumerator = "X",
				expDenominator = "II";
			splitFraction(roman, romanNumerator, romanDenominator);
			Assert::AreEqual(expNumerator, romanNumerator);
			Assert::AreEqual(expDenominator, romanDenominator);
		}
	};
}
