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
		
		TEST_METHOD(True)
		{
			vector<string> errors;
			string roman = "I";
			int expResult = 1;
			int result = romanToInt(roman, errors);
			Assert::AreEqual(expResult, result);
		}
		TEST_METHOD(False)
		{
			vector<string> errors;
			string roman = "I";
			int expResult = 1;
			int result = romanToInt(roman, errors);
			Assert::AreEqual(expResult, result);
		}
	};
}
