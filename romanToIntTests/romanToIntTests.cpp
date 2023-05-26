#include "pch.h"
#include "CppUnitTest.h"
#include "../kinpo/functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace romanToIntTests
{
	TEST_CLASS(romanToIntTests)
	{
	public:

		TEST_METHOD(simpleSingleDigit) //Простое однозначное число
		{
			int result = romanToInt("I"),
				expResult = 1;
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(simpleTwoDigitNumber) //Простое двузначное число
		{
			int result = romanToInt("L"),
				expResult = 50;
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(simpleThreeDigitNumber) //Простое трёхзначное число
		{
			int result = romanToInt("D"),
				expResult = 500;
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(simpleFourDigitNumber) //Простое четырехзначное число
		{
			int result = romanToInt("M"),
				expResult = 1000;
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(compositeSingleDigitNumber) //Составное однозначное число
		{
			int result = romanToInt("VIII"),
				expResult = 8;
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(compositeTwoDigitNumber) //Составное двузначное число
		{
			int result = romanToInt("XXII"),
				expResult = 22;
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(compositeThreeDigitNumber) //Составное трёхзначное число
		{
			int result = romanToInt("DCCCLXXXVIII"),
				expResult = 888;
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(compositeFourDigitNumber) //Составное четырехзначное число
		{
			int result = romanToInt("MMDCXCIII"),
				expResult = 2693;
			Assert::AreEqual(expResult, result);
		}
	};
}
