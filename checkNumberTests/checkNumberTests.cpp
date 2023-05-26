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
		

		TEST_METHOD(tooLongNumber)
		{
				string result = checkNumber("MMMDCCCLXXXVIIII"),
					expResult = "����� ����� �� ����� ���� ������ 15 ��������.";
				Assert::AreEqual(expResult, result);
		}

	};
}
