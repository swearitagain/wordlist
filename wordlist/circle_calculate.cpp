#include "pch.h"
#include "circle_calculate.h"

circle_calculate::circle_calculate(vector<string> words, bool more_letter, int assigned_initail, int assigned_tail,
	int circle) :specified_calculate(words, more_letter, assigned_initail, assigned_tail)
{
	this->circle = circle;
}

circle_calculate::~circle_calculate()
{
}

bool circle_calculate::chain_find_next(word_node prev_node)
{
	if(!circle)
	{
		return specified_calculate::chain_find_next(prev_node);
	}
	vector<word_node> *word_nodes = &word_map[prev_node.get_tail()];
	bool has_next_word = false;
	if (word_nodes->size() == 0)
	{
		check_current_chain();
		return true;
	}
	for (auto current_node = word_nodes->begin(); current_node < word_nodes->end(); ++current_node)
	{
		if (current_node->is_used())
		{
			continue;
		}
		has_next_word = true;
		current_word_chain.push_back(current_node->get_word());
		current_letter_count += current_node->get_length();

		current_node->set_used();
		if (!chain_find_next(*current_node))
		{
			return false;
		}
		current_node->clear_used();
	}
	if (!has_next_word)
	{
		check_current_chain();
		return true;
	}
	return true;
}
