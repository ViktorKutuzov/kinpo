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
					expResult = "Длина числа не может быть больше 15 символов.";
				Assert::AreEqual(expResult, result);
		}

	};
}
