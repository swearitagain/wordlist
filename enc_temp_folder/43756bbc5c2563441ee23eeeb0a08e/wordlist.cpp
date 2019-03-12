// wordlist.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include "pch.h"

#include "input_output.h"

using namespace std;
extern "C" __declspec(dllimport) int gen_chain(char* words[], int len, char* result[]);
extern "C" __declspec(dllimport) int gen_chain_word(char* words[], int len, char* result[], char head, char tail, bool enable_loop);
extern "C" __declspec(dllimport) int gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop);
extern "C" __declspec(dllimport) void char_star_to_string(char* words[], int len, vector<string> *word_vector);
extern "C" __declspec(dllimport) void string_to_char_star(char* result[], vector<string>* result_vector);


int main()
{
	try {
		//-w ‪E:\sofware engineering\pair programming\wordlist\test_case\test_case1.txt
		//-w ‪E:\sofware engineering\pair programming\wordlist\test_case\test_case2.txt
		//-w ‪E:\sofware engineering\pair programming\wordlist\test_case\test_case3.txt
		//-w ‪E:\sofware engineering\pair programming\wordlist\test_case\test_case4.txt
		input_output in_out;
		vector<string> raw_input_words = in_out.input();
		char *result[1000];
		int result_len;

		char *input_words[1000];
		for (int i = 0; i < raw_input_words.size(); i++) {
			const char *word = raw_input_words.at(i).data();
			char * wordArr = new char[strlen(word) + 1];
			input_words[i] = wordArr;
			for (int k = 0; k < strlen(word) + 1; k++) {
				wordArr[k] = word[k];
			}
		}

		for (int i = 0; i < raw_input_words.size(); i++) {
			cout << input_words[i] << endl;
		}

		//1. 测试正常-w | 成环测试
		result_len = gen_chain(input_words, raw_input_words.size(),result);
		cout << result_len << endl;
		for (int i = 0; i < result_len; i++) {
			cout << result[i] << endl;
		}

		//输出到文件
		vector<string> result_v;
		for (int i = 0; i < result_len; i++) {
			result_v.push_back(result[i]);
		}
		in_out.output(result_v);

		//2. 测试-h -t参数
		char *result2[1000];
		result_len = gen_chain_word(input_words,raw_input_words.size(),result2,'e',0,false);
		cout << result_len << endl;
		for (int i = 0; i < result_len; i++) {
			cout << result2[i] << endl;
		}

		//3. 测试-c 参数
		char *result3[1000];
		result_len = gen_chain_char(input_words, raw_input_words.size(), result3, 0, 0, false);
		cout << result_len << endl;
		for (int i = 0; i < result_len; i++) {
			cout << result3[i] << endl;
		}

		//4. 压力测试
		char *result4[1000];
		cout << "begin" << endl;
		result_len = gen_chain_word(input_words, raw_input_words.size(), result4, 0, 0, true);
		cout << result_len << endl;
		for (int i = 0; i < result_len; i++) {
			cout << result4[i] << endl;
		}
		cout << "end" << endl;

	}
	catch (exception e) {
		cout << e.what() << endl;
	}

	try {
		vector<string> raw_input_words;
		char *input_words_tmp[1] = {};
		char *result_tmp[1] = {};
		gen_chain(input_words_tmp,1, result_tmp);

	}
	catch (exception e) {
		e.what();
	}


	//----split----
	//----main function----


	system("pause");
}

