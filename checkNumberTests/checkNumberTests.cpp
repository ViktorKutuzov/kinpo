#include "pch.h"
#include "CppUnitTest.h"
#include "../kinpo/functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace checkNumberTests
{
	TEST_CLASS(checkNumberTests)
	{
	public:


		TEST_METHOD(tooLongNumber) //������� ������� �����
		{
				string result = checkNumber("MMMDCCCLXXXVIIII"),
					expResult = "����� ����� �� ����� ���� ������ 15 ��������.";
				Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(undefinedSymbol) //������������ ������
		{
			string result = checkNumber("qXX"),
				expResult = "C����� ����� 1 ���������.";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(symbolOverflow) //������������ �������
		{
			string result = checkNumber("IIII"),
				expResult = "������ I, ����� 4 � ������, �� ����� ���� ����� III";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(forbiddenCombWithI) //����������� ��������� ������� � I
		{
			string result = checkNumber("IL"),
				expResult = "������ L, ����� 2 � ������, �� ����� ���� ����� I";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(forbiddenCombWithV) //����������� ��������� ������� � V
		{
			string result = checkNumber("VX"),
				expResult = "������ X, ����� 2 � ������, �� ����� ���� ����� V";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(forbiddenCombWithX) //����������� ��������� ������� � X
		{
			string result = checkNumber("XD"),
				expResult = "������ D, ����� 2 � ������, �� ����� ���� ����� X";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(forbiddenCombWithL) //����������� ��������� ������� � L
		{
			string result = checkNumber("LC"),
				expResult = "������ C, ����� 2 � ������, �� ����� ���� ����� L";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(forbiddenCombWithD) //����������� ��������� ������� � D
		{
			string result = checkNumber("DM"),
				expResult = "������ M, ����� 2 � ������, �� ����� ���� ����� D";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(overflowV) //������������ ������� V
		{
			string result = checkNumber("VV"),
				expResult = "������ V, ����� 2 � ������, �� ����� ���� ����� V";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(overflowM) //������������ ������� M
		{
			string result = checkNumber("MMMM"),
				expResult = "������ M, ����� 4 � ������, �� ����� ���� ����� MMM";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(subtractionInRow) //��������� ������
		{
			string result = checkNumber("IXC"),
				expResult = "������ C, ����� 3 � ������, �� ����� ���� ����� IX";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(incorrectOccurrenceOfI) //������������ ��������� ������� I
		{
			string result = checkNumber("IXI"),
				expResult = "������ I, ����� 3 � ������, �� ����� ���� ����� IX";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(incorrectOccurrenceOfV) //������������ ��������� ������� V
		{
			string result = checkNumber("LXC"),
				expResult = "������ C, ����� 3 � ������, �� ����� ���� ����� LX";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(incorrectOccurrenceOfX) //������������ ��������� ������� X
		{
			string result = checkNumber("XVX"),
				expResult = "������ X, ����� 3 � ������, �� ����� ���� ����� XV";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(incorrectOccurrenceOfL) //������������ ��������� ������� L
		{
			string result = checkNumber("XCL"),
				expResult = "������ L, ����� 3 � ������, �� ����� ���� ����� XC";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(incorrectOccurrenceOfC) //������������ ��������� ������� C
		{
			string result = checkNumber("MLC"),
				expResult = "������ C, ����� 3 � ������, �� ����� ���� ����� ML";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(incorrectOccurrenceOfD) //������������ ��������� ������� D
		{
			string result = checkNumber("CXD"),
				expResult = "������ D, ����� 3 � ������, �� ����� ���� ����� CX";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(incorrectOccurrenceOfM) //������������ ��������� ������� M
		{
			string result = checkNumber("MMCDM"),
				expResult = "������ M, ����� 5 � ������, �� ����� ���� ����� MMCD";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(noError) //��� ������
		{
			string expResult = "";
			for (int i = 1; i < 4000; ++i) //��� ������� ����� �� 1 �� 3999
			{
				string result = checkNumber(intToRoman(i));
				Assert::AreEqual(expResult, result);
			}
		}
	};
}
