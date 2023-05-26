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

		TEST_METHOD(simpleSingleDigit) //������� ����������� �����
		{
			int result = romanToInt("I"),
				expResult = 1;
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(simpleTwoDigitNumber) //������� ���������� �����
		{
			int result = romanToInt("L"),
				expResult = 50;
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(simpleThreeDigitNumber) //������� ���������� �����
		{
			int result = romanToInt("D"),
				expResult = 500;
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(simpleFourDigitNumber) //������� �������������� �����
		{
			int result = romanToInt("M"),
				expResult = 1000;
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(compositeSingleDigitNumber) //��������� ����������� �����
		{
			int result = romanToInt("VIII"),
				expResult = 8;
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(compositeTwoDigitNumber) //��������� ���������� �����
		{
			int result = romanToInt("XXII"),
				expResult = 22;
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(compositeThreeDigitNumber) //��������� ���������� �����
		{
			int result = romanToInt("DCCCLXXXVIII"),
				expResult = 888;
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(compositeFourDigitNumber) //��������� �������������� �����
		{
			int result = romanToInt("MMDCXCIII"),
				expResult = 2693;
			Assert::AreEqual(expResult, result);
		}
	};
}
