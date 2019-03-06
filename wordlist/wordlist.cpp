// wordlist.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "calculate.h"
#include "specified_calculate.h"
#include "circle_calculate.h"
#include <string>
#include "core.h"

int main()
{
    std::cout << "Hello World!\n";

	char a[] = "ab";
	char b[] = "bv";
	char *words[] = {a,b};

	int length = 2;
	char * result[2] = { b,a };
	vector<string> *result_v = nullptr;
	core *my_core = new core();
	try {
		my_core->gen_chain(words, length, result);
		result_v = my_core->gen_chain_word_v({ "half", "pig", "giggle", "fun", "none" }, 0, 0, false);
	}catch (exception e)
	{
		cout << e.what() << endl;
	}
	for(int i = 0; i < length; i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;
	for (int i = 0 ; i < result_v->size();i++)
	{
		cout << result_v->at(i) << " ";
	}
	//calculateInterface *cal = new calculate({ "half", "pig", "giggle", "fun", "none" }, false);
	//vector<string> *result = cal->get_result();

	//delete cal;

	//cal = new specified_calculate({ "half", "pig", "giggle", "fun", "none" }, false, ALPHA_TO_INDEX('p'), -1);
	//result = cal->get_result();

	//delete cal;

	//cal = new specified_calculate({ "half", "pig", "giggle", "fun", "niupi" }, false, -1, ALPHA_TO_INDEX('e'));
	//result = cal->get_result();

	//delete cal;

	//cal = new circle_calculate({ "half", "pig", "gap", "fun", "neo", "op" }, false, -1, -1, true);
	//result = cal->get_result();

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
