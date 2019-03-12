#include "stdafx.h"
#include "CppUnitTest.h"
#include <iostream>
//#include "../wordlist/core.h"
#include "../makedll/core.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace wordlist_unit_test
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			//Assert:E:\sofware engineering\pair programming\wordlist\x64\Debug\w:AreEqual(1, 1);
		}


		TEST_METHOD(test_gen_chain) {
			char *result[4];
			char *words[4] = { "END", "OF", "THE", "WORLD" };
			Assert::AreEqual(2, core::gen_chain(words, 4, result));
			Assert::AreEqual(0, core::gen_chain_word(words, 4, result,'a','b',0));
		}

		TEST_METHOD(test_gen_chain2) {

		}
	};
}