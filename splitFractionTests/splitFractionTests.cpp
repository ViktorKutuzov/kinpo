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
		
		TEST_METHOD(noNumerator) //ќтсутствует числитель дроби
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
					expResult = "ќтсутствует числитель дроби. ¬ведите числитель, символ разделител€ \"/\", знаменатель, не раздел€€ их пробелами.";
				Assert::AreEqual(expResult, result);
			}
		}

		TEST_METHOD(noDenominator) //ќтсутствует знаменатель дроби
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
					expResult = "ќтсутствует знаменатель дроби. ¬ведите числитель, символ разделител€ \"/\", знаменатель, не раздел€€ их пробелами.";
				Assert::AreEqual(expResult, result);
			}
		}

		TEST_METHOD(noDelimiter) //ќтсутствует символ разделител€
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
					expResult = "ќтсутствует символ разделител€. ¬ведите числитель, символ разделител€ \"/\", знаменатель, не раздел€€ их пробелами.";
				Assert::AreEqual(expResult, result);
			}
		}

		TEST_METHOD(noInputData) //ќтсутствуют входные данные.
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
					expResult = "ќтсутствуют входные данные.";
				Assert::AreEqual(expResult, result);
			}
		}

		TEST_METHOD(NoErrorsFraction) //ѕравильна€ запись дроби
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
