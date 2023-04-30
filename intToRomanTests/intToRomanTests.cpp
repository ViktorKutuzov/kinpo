#include "pch.h"
#include "CppUnitTest.h"
#include <string.h>
#include "../kinpo/functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace intToRomanTests
{
	TEST_CLASS(intToRomanTests)
	{
	public:
		
		TEST_METHOD(simpleSingleDigit)
		{
			string result = intToRoman(1);
			string expResult = "I";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(simpleTwoDigitNumber)
		{
			string result = intToRoman(50);
			string expResult = "L";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(simpleThreeDigitNumber)
		{
			string result = intToRoman(500);
			string expResult = "D";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(simpleFourDigitNumber)
		{
			string result = intToRoman(1000);
			string expResult = "M";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(compositeSingleDigitNumber)
		{
			string result = intToRoman(8);
			string expResult = "VIII";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(compositeTwoDigitNumber)
		{
			string result = intToRoman(22);
			string expResult = "XXII";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(compositeThreeDigitNumber)
		{
			string result = intToRoman(999);
			string expResult = "CMXCIX";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(compositeFourDigitNumber)
		{
			string result = intToRoman(3456);
			string expResult = "MMMCDLVI";
			Assert::AreEqual(expResult, result);
		}
	};
}
