#pragma once

#include <vector>

#include <string>
using namespace std;

class core
{
//该类封装了计算模块，拥有五个接口，其中前三个接口为标准要求接口
//分别为gen_chain, gen_chain_word,gen_chain_char
//words为输入的单词列表，len为单词列表的长度，result存放单词链
//head和tail分别为单词链首字母与尾字母约束
//当enable_loop为true时表示允许输入单词文本中隐含“单词环”

//后两个接口类似，只是输入输出换成了vector<string>和vector<string>*
public:
	core();
	static void char_star_to_string(char* words[], int len, vector<string> *word_vector);
	static void string_to_char_star(char* result[], vector<string>* result_vector);
	static void check_head_tail(char head, char tail);
	//计算最多单词数量的最长单词链
	static int gen_chain(char* words[], int len, char* result[]);
	//计算最多单词数量的最长单词链
	static int gen_chain_word(char* words[], int len, char* result[], char head, char tail, bool enable_loop);
	//计算最多字母数量的最长单词链
	static int gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop);

	~core();
private:

};
