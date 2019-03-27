// wordlist.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#include <iostream>
#include <string>
#include "input_output.h"

using namespace std;

extern "C" __declspec(dllimport) int gen_chain(char* words[], int len, char* result[]);
extern "C" __declspec(dllimport) int gen_chain_word(char* words[], int len, char* result[], char head, char tail, bool enable_loop);
extern "C" __declspec(dllimport) int gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop);

int main()
{
	try {
		input_output in_out;
		vector<string> raw_input_words = in_out.input();
		char *result[1000];
		int result_len = 0;

		char *input_words[1000];
		for (int i = 0; i < raw_input_words.size(); i++) {
			const char *word = raw_input_words.at(i).data();
			char * wordArr = new char[strlen(word) + 1];
			input_words[i] = wordArr;
			for (int k = 0; k < strlen(word) + 1; k++) {
				wordArr[k] = word[k];
			}
		}

		if (in_out.is_w)
			result_len = gen_chain_word(input_words, raw_input_words.size(), result, in_out.is_h, in_out.is_t, in_out.is_r);
		if (in_out.is_c)
			result_len = gen_chain_char(input_words, raw_input_words.size(), result, in_out.is_h, in_out.is_t, in_out.is_r);

		//输出到文件
		vector<string> result_v;
		for (int i = 0; i < result_len; i++) {
			result_v.push_back(result[i]);
		}
		in_out.output(result_v);
	}
	catch (exception e) {
		e.what();
	}

	system("pause");
}