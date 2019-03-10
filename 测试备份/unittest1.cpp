#include "stdafx.h"
#include "CppUnitTest.h"
//#include "../wordlist/calculate.h"
//#include "../wordlist/calculateInterface.h"
//#include "../wordlist/circle_calculate.h"
//#include "../wordlist/input_output.h"
//#include "../wordlist/word_node.h"
#include "../wordlist/core.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace wordlist_unit_test
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(1, 1);
		}


		TEST_METHOD(test_gen_chain) {
			char *result[4];
			char *words[4] = { (char*)"END", (char*)"OF", (char*)"THE", (char*)"WORLD" };
			int x = core::gen_chain(words, 4, result);
			//Assert::AreEqual(4,core::gen_chain(words,4,result));
			//Assert::AreEqual(4, x);
		}
	};
}