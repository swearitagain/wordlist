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
	calculate(vector<string> words, bool more_letter);
	~calculate();
	vector<string> *get_result() override;

private:
	vector<word_node> word_map[ALPHA_COUNT];

	bool has_circle = false;
	bool more_letter;
	int longest_letter_count = 0;
	int current_letter_count = 0;
	vector<string> longest_word_chain;	//�������
	vector<string> current_word_chain;	//��ǰ������
	bool chain_find_next(word_node prev_node);
	void check_current_chain();
};


