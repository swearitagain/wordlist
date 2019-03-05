#include "pch.h"
#include "specified_calculate.h"


specified_calculate::specified_calculate(vector<string> words, bool more_letter, int assigned_initail, int assigned_tail) :
	calculate(words, more_letter)
{
	this->assigned_initial = assigned_initail;
	this->assigned_tail = assigned_tail;
}


specified_calculate::~specified_calculate()
{
}

vector<string>* specified_calculate::get_result()
{
	if (assigned_initial == -1) 
	{
		return calculate::get_result();
	}
	for (auto current_node = word_map[assigned_initial].begin(); current_node < word_map[assigned_initial].end(); ++current_node)
	{
		current_word_chain.clear();
		current_letter_count = 0;
		current_word_chain.push_back(current_node->get_word());
		current_letter_count += current_node->get_length();

		current_node->set_used();
		if (!chain_find_next(*current_node))
		{
			return nullptr;
		}
		current_node->clear_used();
	}
	return &longest_word_chain;
}

void specified_calculate::check_current_chain()
{
	string last_word = current_word_chain.back();
	const int last_letter = ALPHA_TO_INDEX(last_word[last_word.size() - 1]);
	if (assigned_tail == -1 || last_letter == assigned_tail) 
	{
		calculate::check_current_chain();
	}
}
