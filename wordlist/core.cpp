#include "pch.h"
#include "core.h"
#include <vector>
#include <string>
#include "calculate.h"
#include <iostream>
#include "specified_calculate.h"
#include "circle_calculate.h"
#pragma warning(disable:4996)

using namespace std;


core::core()
{
}

void core::char_star_to_string(char* words[], int len, vector<string> *word_vector)
{
	for (int i = 0; i < len; i++)
	{
		word_vector->push_back(words[i]);
	}
}

void core::string_to_char_star(char* words[], vector<string>* word_vector)
{
	for(auto i = 0; i < word_vector->size(); i++)
	{
		////words[i] = new char[word_vector->at(i).size()];
		//words[i] = const_cast<char*>(word_vector->at(i).c_str());
		//words[i][word_vector->at(i).size()] = '\0';
		//new 为了解决core被析构之后指针指向的单词也被析构的问题
		words[i] = new char[word_vector->at(i).size()];
		strcpy(words[i], word_vector->at(i).c_str());
	}
}

int core::gen_chain(char* words[], int len, char* result[])
{
	vector<string> word_vector;
	char_star_to_string(words, len, &word_vector);

	calculate calculate(word_vector, false);
	vector<string> *result_vector = calculate.get_result();

	if(result_vector== nullptr)
	{
		throw exception("单词文本隐含单词环");
	}

	string_to_char_star(result, result_vector);
	return result_vector->size();
}

int core::gen_chain_word(char* words[], int len, char* result[], char head, char tail, bool enable_loop)
{
	vector<string> word_vector;
	char_star_to_string(words, len, &word_vector);

	if((head < 'a' || head > 'z') && head != 0)
	{
		throw exception("首字母约束不合法”");
	}
	if((tail < 'a' || tail > 'z') && tail != 0)
	{
		throw exception("尾字母约束不合法”");
	}

	circle_calculate calculate(word_vector, false, head == 0 ? -1 : ALPHA_TO_INDEX(head), tail == 0 ? -1 : ALPHA_TO_INDEX(tail),enable_loop);
	vector<string> *result_vector = calculate.get_result();

	if (!enable_loop && result_vector == nullptr)
	{
		throw exception("单词文本隐含单词环");
	}

	string_to_char_star(result, result_vector);
	return result_vector->size();
}

int core::gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop)
{
	vector<string> word_vector;
	char_star_to_string(words, len, &word_vector);

	if ((head < 'a' || head > 'z') && head != 0)
	{
		throw exception("首字母约束不合法”");
	}
	if ((tail < 'a' || tail > 'z') && tail != 0)
	{
		throw exception("尾字母约束不合法”");
	}

	circle_calculate calculate(word_vector, true, head == 0 ? -1 : ALPHA_TO_INDEX(head), tail == 0 ? -1 : ALPHA_TO_INDEX(tail), enable_loop);
	vector<string> *result_vector = calculate.get_result();

	if (!enable_loop && result_vector == nullptr)
	{
		throw exception("单词文本隐含单词环");
	}

	string_to_char_star(result, result_vector);
	return result_vector->size();
}

vector<string>* core::gen_chain_word_v(vector<string> words, char head, char tail, bool enable_loop)
{
	if ((head < 'a' || head > 'z') && head != 0)
	{
		throw exception("首字母约束不合法”");
	}
	if ((tail < 'a' || tail > 'z') && tail != 0)
	{
		throw exception("尾字母约束不合法”");
	}

	circle_calculate calculate(words, false, head == 0 ? -1 : ALPHA_TO_INDEX(head), tail == 0 ? -1 : ALPHA_TO_INDEX(tail), enable_loop);
	return new vector<string>(*calculate.get_result());
}

vector<string>* core::gen_chain_char_v(vector<string> words, char head, char tail, bool enable_loop)
{
	if ((head < 'a' || head > 'z') && head != 0)
	{
		throw exception("首字母约束不合法”");
	}
	if ((tail < 'a' || tail > 'z') && tail != 0)
	{
		throw exception("尾字母约束不合法”");
	}

	circle_calculate calculate(words, true, head == 0 ? -1 : ALPHA_TO_INDEX(head), tail == 0 ? -1 : ALPHA_TO_INDEX(tail), enable_loop);
	return new vector<string>(*calculate.get_result());
}


core::~core()
{
}
