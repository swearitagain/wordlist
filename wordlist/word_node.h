#pragma once
#include <string>

using namespace std;
//单词链表结点
class word_node
{
public:
	word_node(int length, int tail, string word);
	int get_length() const;
	int get_tail() const;
	string get_word() const;
	bool is_used();
	void set_used();
	void clear_used();
private:
	string word;
	int length;	//单词长度
	int tail;	//单词尾字母所对应序号
	bool used;	//单词是否在遍历过程中被使用过

};