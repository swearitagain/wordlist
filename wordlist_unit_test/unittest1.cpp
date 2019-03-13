#include "stdafx.h"
#include "CppUnitTest.h"
#include <iostream>
//#include "../wordlist/core.h"
//#include "../makedll/core.h"
#include "../wordlist/input_output.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

extern "C" __declspec(dllimport) int gen_chain(char* words[], int len, char* result[]);
extern "C" __declspec(dllimport) int gen_chain_word(char* words[], int len, char* result[], char head, char tail, bool enable_loop);
extern "C" __declspec(dllimport) int gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop);

namespace wordlist_unit_test
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(test_gen_chain_w) {
			char *result[4];
			char *words[4] = { "END", "OF", "THE", "WORLD" };
			Assert::AreEqual(2, gen_chain(words, 4, result));
		}

		TEST_METHOD(test_gen_chain_w_2) {
			char *result[4];
			char *words[4] = { "END", "OF", "THE", "WORLD" };
			Assert::AreEqual(2, gen_chain_word(words, 4, result, 0, 0, 0));
		}

		TEST_METHOD(test_gen_chain_w_3) {
			char *result[4];
			char *words[4] = { "END", "OF", "THE", "WORLD" };
			Assert::AreEqual(0, gen_chain_word(words, 4, result, 'm', 0, 0));
		}

		TEST_METHOD(test_gen_chain_c) {
			char *result[4];
			char *words[4] = { "END", "OF", "THE", "WORLD" };
			Assert::AreEqual(2, gen_chain_char(words, 4, result, 0, 0, 0));
		}

		TEST_METHOD(test_gen_chain_c_2) {
			char *result[4];
			char *words[4] = { "Hello", "oom", "mr", "xxxxxxxxxxxp" };
			Assert::AreEqual(3, gen_chain_char(words, 4, result, 0, 0, 0));
		}

		TEST_METHOD(test_gen_chain_c_3) {
			char *result[4];
			char *words[6] = { "Hello", "oom", "mr", "xxxxxxxxxxxp","iiii","eeeee" };
			Assert::AreEqual(3, gen_chain_char(words, 4, result, 0, 0, 0));
		}

		//TODO
	};
}