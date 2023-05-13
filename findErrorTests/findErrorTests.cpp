#include "pch.h"
#include "CppUnitTest.h"
#include "../kinpo/functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

void areEqual(const vector<string>expErrors, const vector<string>errors)
{
	size_t n = expErrors.size();
	size_t m = errors.size();
	Assert::AreEqual(n, m);
	if (n == m && n)
	for (size_t i = 0; i < n && i < m; ++i)
	{
		Assert::AreEqual(expErrors[i], errors[i]);
	}
}

namespace findErrorTests
{
	TEST_CLASS(findErrorTests)
	{
	public:
		
		TEST_METHOD(overRepI)
		{
			string roman_numeral = "IIII";
			vector<string> errors;
			vector<string> expErrors = {"������ I �� ����� ����������� ����� 3 ���. ����� ���������� ������� � ������ - 4"};
			findError(roman_numeral, errors);
			areEqual(expErrors, errors);
		}

		TEST_METHOD(nonRepChars)
		{
			string roman_numeral = "LL";
			vector<string> errors;
			vector<string> expErrors = { "������ L �� ����� �����������. ����� ���������� ������� � ������ - 2" };
			findError(roman_numeral, errors);
			areEqual(expErrors, errors);
		}

		TEST_METHOD(charsAfterV)
		{
			string roman_numeral = "VX";
			vector<string> errors;
			vector<string> expErrors = { "����� ������� V �� ����� ���� ������ ��������, ����� I. ����� ���������� ������� � ������ - 2" };
			findError(roman_numeral, errors);
			areEqual(expErrors, errors);
		}

		TEST_METHOD(nonRepI)
		{
			string roman_numeral = "IXI";
			vector<string> errors;
			vector<string> expErrors = { "C����� I ����� ����������� ������ ������. ����� ���������� ������� � ������ - 3" };
			findError(roman_numeral, errors);
			areEqual(expErrors, errors);
		}

		TEST_METHOD(prohibitedCombIL)
		{
			string roman_numeral = "IL";
			vector<string> errors;
			vector<string> expErrors = { "������ L �� ����� ������ ����� ������� I. ����� ���������� ������� � ������ - 2" };
			findError(roman_numeral, errors);
			areEqual(expErrors, errors);
		}

	};
}
