#include "pch.h"
#include "CppUnitTest.h"
#include <string.h>
#include "../kinpo/functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace romanToIntTests
{
	TEST_CLASS(romanToIntTests)
	{
	public:
		
		TEST_METHOD(True)
		{
			std::string roman = "I";
			int expResult = 1;
			int result = romanToInt(roman);
			Assert::AreEqual(expResult, result);
		}
		TEST_METHOD(False)
		{
			std::string roman = "I";
			int expResult = 1;
			int result = romanToInt(roman);
			Assert::AreEqual(expResult, result);
		}
	};
}
