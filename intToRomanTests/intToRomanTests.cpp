#include "pch.h"
#include "CppUnitTest.h"
#include "../kinpo/functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace intToRomanTests
{
	TEST_CLASS(intToRomanTests)
	{
	public:
		
		TEST_METHOD(simpleSingleDigit) //������� ����������� �����
		{
			string result = intToRoman(1),
				expResult = "I";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(simpleTwoDigitNumber) //������� ���������� �����
		{
			string result = intToRoman(50),
				expResult = "L";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(simpleThreeDigitNumber) //������� ���������� �����
		{
			string result = intToRoman(500),
				expResult = "D";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(simpleFourDigitNumber) //������� �������������� �����
		{
			string result = intToRoman(1000),
				expResult = "M";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(compositeSingleDigitNumber) //��������� ����������� �����
		{
			string result = intToRoman(8),
				expResult = "VIII";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(compositeTwoDigitNumber) //��������� ���������� �����
		{
			string result = intToRoman(22),
				expResult = "XXII";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(compositeThreeDigitNumber) //��������� ���������� �����
		{
			string result = intToRoman(999),
				expResult = "CMXCIX";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(compositeFourDigitNumber) //��������� �������������� �����
		{
			string result = intToRoman(3456),
				expResult = "MMMCDLVI";
			Assert::AreEqual(expResult, result);
		}
	};
}
