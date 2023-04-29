#include "pch.h"
#include "CppUnitTest.h"
#include "../kinpo/functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace reduceFractionTests
{
	TEST_CLASS(reduceFractionTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string roman = "XIV/II",
				expResult = "VII";
			string result = reduceFraction(roman);
			Assert::AreEqual(expResult, result);
		}
	};
}
