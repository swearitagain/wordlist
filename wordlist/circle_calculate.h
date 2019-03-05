#pragma once
#include "specified_calculate.h"
class circle_calculate :
	public specified_calculate
{
public:
	//构造函数五个参数：
	//1. 字符串数组，由所有单词构成
	//2. 布尔变量，是否按照字母最多计算单词链
	//3. 整型，指定首字母，-1为不指定，0-26对应26个字母
	//4. 整型，指定尾字母，-1为不指定，0-26对应26个字母
	//5. 布尔类型，是否允许文本隐含单词环
	circle_calculate(vector<string> words, bool more_letter, 
		int assigned_initail, int assigned_tail, int circle);
	~circle_calculate();

	bool chain_find_next(word_node prev_node) override;

protected:
	bool circle;
};

