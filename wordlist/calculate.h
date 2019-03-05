#pragma once
#include "calculateInterface.h"
#include "word_node.h"

#define ALPHA_COUNT 26
#define ALPHA_TO_INDEX(ch) (ch) - 'a'

class word_node;

class calculate :
	public calculateInterface
{
public:
	//构造函数两个参数：
	//1. 字符串数组，由所有单词构成
	//2. 布尔变量，是否按照字母最多计算单词链
	calculate(vector<string> words, bool more_letter);
	~calculate();
	vector<string> *get_result() override;

protected:
	vector<word_node> word_map[ALPHA_COUNT];

	bool has_circle = false;
	bool more_letter;
	int longest_letter_count = 0;
	int current_letter_count = 0;
	vector<string> longest_word_chain;	//最长单词链
	vector<string> current_word_chain;	//当前单词链
	bool chain_find_next(word_node prev_node);
	virtual void check_current_chain();
};


