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


		TEST_METHOD(tooLongNumber) //Слишком большая длина
		{
				string result = checkNumber("MMMDCCCLXXXVIIII"),
					expResult = "Длина числа не может быть больше 15 символов.";
				Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(undefinedSymbol) //Неопознанный символ
		{
			string result = checkNumber("qXX"),
				expResult = "Cимвол номер 1 неопознан.";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(symbolOverflow) //Переполнение символа
		{
			string result = checkNumber("IIII"),
				expResult = "Символ I, номер 4 в строке, не может идти после III";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(forbiddenCombWithI) //Запрещенное сочетание символа с I
		{
			string result = checkNumber("IL"),
				expResult = "Символ L, номер 2 в строке, не может идти после I";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(forbiddenCombWithV) //Запрещенное сочетание символа с V
		{
			string result = checkNumber("VX"),
				expResult = "Символ X, номер 2 в строке, не может идти после V";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(forbiddenCombWithX) //Запрещенное сочетание символа с X
		{
			string result = checkNumber("XD"),
				expResult = "Символ D, номер 2 в строке, не может идти после X";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(forbiddenCombWithL) //Запрещенное сочетание символа с L
		{
			string result = checkNumber("LC"),
				expResult = "Символ C, номер 2 в строке, не может идти после L";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(forbiddenCombWithD) //Запрещенное сочетание символа с D
		{
			string result = checkNumber("DM"),
				expResult = "Символ M, номер 2 в строке, не может идти после D";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(overflowV) //Переполнение символа V
		{
			string result = checkNumber("VV"),
				expResult = "Символ V, номер 2 в строке, не может идти после V";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(overflowM) //Переполнение символа M
		{
			string result = checkNumber("MMMM"),
				expResult = "Символ M, номер 4 в строке, не может идти после MMM";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(subtractionInRow) //Вычитание подряд
		{
			string result = checkNumber("IXC"),
				expResult = "Символ C, номер 3 в строке, не может идти после IX";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(incorrectOccurrenceOfI) //Некорректное вхождение символа I
		{
			string result = checkNumber("IXI"),
				expResult = "Символ I, номер 3 в строке, не может идти после IX";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(incorrectOccurrenceOfV) //Некорректное вхождение символа V
		{
			string result = checkNumber("LXC"),
				expResult = "Символ C, номер 3 в строке, не может идти после LX";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(incorrectOccurrenceOfX) //Некорректное вхождение символа X
		{
			string result = checkNumber("XVX"),
				expResult = "Символ X, номер 3 в строке, не может идти после XV";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(incorrectOccurrenceOfL) //Некорректное вхождение символа L
		{
			string result = checkNumber("XCL"),
				expResult = "Символ L, номер 3 в строке, не может идти после XC";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(incorrectOccurrenceOfC) //Некорректное вхождение символа C
		{
			string result = checkNumber("MLC"),
				expResult = "Символ C, номер 3 в строке, не может идти после ML";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(incorrectOccurrenceOfD) //Некорректное вхождение символа D
		{
			string result = checkNumber("CXD"),
				expResult = "Символ D, номер 3 в строке, не может идти после CX";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(incorrectOccurrenceOfM) //Некорректное вхождение символа M
		{
			string result = checkNumber("MMCDM"),
				expResult = "Символ M, номер 5 в строке, не может идти после MMCD";
			Assert::AreEqual(expResult, result);
		}

		TEST_METHOD(noError) //Нет ошибок
		{
			string expResult = "";
			for (int i = 1; i < 4000; ++i) //Все римские числа от 1 до 3999
			{
				string result = checkNumber(intToRoman(i));
				Assert::AreEqual(expResult, result);
			}
		}
	};
}
