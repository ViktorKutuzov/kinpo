#include "pch.h"
#include "CppUnitTest.h"
#include <string.h>
#include "../kinpo/functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace intToRomanTests
{
	TEST_CLASS(intToRomanTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string result = intToRoman(1);
			string expResult = "I";
			Assert::AreEqual(expResult, result);
		}
	};
}
