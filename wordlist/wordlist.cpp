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
//extern "C" __declspec(dllimport) vector<string>* gen_chain_word_v(vector<string> words, char head, char tail, bool enable_loop);
//extern "C" __declspec(dllimport) vector<string>* gen_chain_char_v(vector<string> words, char head, char tail, bool enable_loop);


int main()
{
 //   std::cout << "Hello World!\n";

	//char a[] = "ab";
	//char b[] = "bv";
	//char *words[] = {a,b};

	//int length = 2;
	//char * result[2] = { b,a };
	//for(int i = 0; i < length; i++)
	//{
	//	cout << result[i] << " ";
	//}
	//cout << endl;

	//vector<string> *result_v = nullptr;
	//core *my_core = new core();
	//try {
	//	//my_core->gen_chain(words, length, result);
	//	result_v = my_core->gen_chain_word_v({ "half", "pig", "giggle", "fun", "none" }, 0, 0, false);
	//}catch (exception e)
	//{
	//	cout << e.what() << endl;
	//}

	//for (int i = 0 ; i < result_v->size();i++)
	//{
	//	cout << result_v->at(i) << " ";
	//}

	//calculateInterface *cal = new calculate({ "half", "pig", "giggle", "fun", "none" }, false);
	////vector<string> *result = cal->get_result();

	////delete cal;

	//vector<string>* result2;
	//cal = new specified_calculate({ "half", "pig", "giggle", "fun", "none" }, false, ALPHA_TO_INDEX('p'), -1);
	//result2 = cal->get_result();

	//delete cal;

	//cal = new specified_calculate({ "half", "pig", "giggle", "fun", "niupi" }, false, -1, ALPHA_TO_INDEX('e'));
	//result2 = cal->get_result();

	//delete cal;

	//cal = new circle_calculate({ "half", "pig", "gap", "fun", "neo", "op" }, false, -1, -1, true);
	//result2 = cal->get_result();

	//system("pause");

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

		//6.其他函数测试
		//gen_chain_word_v(raw_input_words, 0, 0, true);
		//gen_chain_char_v(raw_input_words, 0, 0, true);


	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	system("pause");
}

