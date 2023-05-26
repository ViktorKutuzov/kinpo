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
		
		TEST_METHOD(fractionReducedWithoutErrorTest1) //����� ����������� ��� ������
		{
			string romanNumerator = "XIV",
				romanDenominator = "II",
				expResult = "VII",
				result = reduceFraction(romanNumerator, romanDenominator);
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(fractionReducedWithoutErrorTest2) //����� ����������� ��� ������
		{
			string romanNumerator = "MMMCD",
				romanDenominator = "XVII",
				expResult = "CC",
				result = reduceFraction(romanNumerator, romanDenominator);
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(reducedFractionHasDenominatorI) //����������� ����� ����� ����������� �I�
		{
			string romanNumerator = "X",
				romanDenominator = "X",
				expResult = "I",
				result = reduceFraction(romanNumerator, romanDenominator);
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(fractionHasDenominatorI) //����� ����� ����������� �I�
		{
			string romanNumerator = "X",
				romanDenominator = "I",
				expResult = "X",
				result = reduceFraction(romanNumerator, romanDenominator);
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(fractionCantBeReducedTest1) //����� ������ ���������
		{
			string romanNumerator = "XIII",
				romanDenominator = "XI",
				expResult = "XIII/XI",
				result = reduceFraction(romanNumerator, romanDenominator);
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(fractionCantBeReducedTest2) //����� ������ ���������
		{
			string romanNumerator = "MMMCMXCIX",
				romanDenominator = "XIII",
				expResult = "MMMCMXCIX/XIII",
				result = reduceFraction(romanNumerator, romanDenominator);
			Assert::AreEqual(expResult, result);
		}
	};
}
