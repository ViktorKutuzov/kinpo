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
		
		TEST_METHOD(noNumerator) //����������� ��������� �����
		{
			try
			{
				string roman = "/II",
					romanNumerator = {},
					romanDenominator = {};
				splitFraction(roman, romanNumerator, romanDenominator);
			}
			catch (std::runtime_error& ex)
			{
				string result = ex.what(),
					expResult = "����������� ��������� �����. ������� ���������, ������ ����������� \"/\", �����������, �� �������� �� ���������.";
				Assert::AreEqual(expResult, result);
			}
		}

		TEST_METHOD(noDenominator) //����������� ����������� �����
		{
			try
			{
				string roman = "X/",
					romanNumerator = {},
					romanDenominator = {};
				splitFraction(roman, romanNumerator, romanDenominator);
			}
			catch (std::runtime_error& ex)
			{
				string result = ex.what(),
					expResult = "����������� ����������� �����. ������� ���������, ������ ����������� \"/\", �����������, �� �������� �� ���������.";
				Assert::AreEqual(expResult, result);
			}
		}

		TEST_METHOD(noDelimiter) //����������� ������ �����������
		{
			try
			{
				string roman = "XII",
					romanNumerator = {},
					romanDenominator = {};
				splitFraction(roman, romanNumerator, romanDenominator);
			}
			catch (std::runtime_error& ex)
			{
				string result = ex.what(),
					expResult = "����������� ������ �����������. ������� ���������, ������ ����������� \"/\", �����������, �� �������� �� ���������.";
				Assert::AreEqual(expResult, result);
			}
		}

		TEST_METHOD(noInputData) //����������� ������� ������.
		{
			try
			{
				string roman = "",
					romanNumerator = {},
					romanDenominator = {};
				splitFraction(roman, romanNumerator, romanDenominator);
			}
			catch (std::runtime_error& ex)
			{
				string result = ex.what(),
					expResult = "����������� ������� ������.";
				Assert::AreEqual(expResult, result);
			}
		}

		TEST_METHOD(NoErrorsFraction) //���������� ������ �����
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
