// wordlist.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include "pch.h"
#include "calculate.h"
#include "specified_calculate.h"
#include "circle_calculate.h"
#include "core.h"
#include "input_output.h"

using namespace std;

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

	//输入测试
	//-w ‪E:\sofware engineering\pair programming\wordlist\test dependency backup\test_case1.txt
	input_output in_out;
	vector<string> raw_input_words = in_out.input();
	char *result[1000];
	int result_len;
	core *my_core = new core();

	char *input_words[1000];
	for (int i = 0; i < raw_input_words.size(); i++) {
		const char *word = raw_input_words.at(i).data();
		char * wordArr = new char[strlen(word) + 1];
		input_words[i] = wordArr;
		for (int k = 0; k < strlen(word) + 1; k++) {
			wordArr[k] = word[k];
		}
	}

	//for (int i = 0; i < raw_input_words.size(); i++) {
	//	cout << input_words[i] << endl;
	//}
	try {
		//1. 测试正常-w
		result_len = my_core->gen_chain(input_words, raw_input_words.size(),result);
		cout << result_len << endl;
		for (int i = 0; i < 2; i++) {
			cout << result[i] << endl;
		}

		//2. 测试-h -t参数


		//3. 测试-c 参数


		//4. 
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	system("pause");
}

