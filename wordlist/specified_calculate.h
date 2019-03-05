#pragma once
#include "calculate.h"
class specified_calculate :
	public calculate
{
public:
	//构造函数四个参数：
	//1. 字符串数组，由所有单词构成
	//2. 布尔变量，是否按照字母最多计算单词链
	//3. 整型，指定首字母，-1为不指定，0-26对应26个字母
	//4. 整型，指定尾字母，-1为不指定，0-26对应26个字母
	specified_calculate(vector<string> words, bool more_letter, int assigned_initail, int assigned_tail);
	~specified_calculate();
	vector<string> *get_result() override;
	void check_current_chain() override;

protected:
	int assigned_initial;
	int assigned_tail;
};

