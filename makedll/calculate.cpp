#include "stdafx.h"
#include "calculate.h"
#include<string>

using namespace std;

string to_lower_case(string s)
{
	for (auto i = 0; i < s.length(); i++)
	{
		if(s[i] <= 'Z' && s[i] >= 'A')
		{
			s[i] = s[i] - 'A' + 'a';
		}
	}
	return s;
}

bool calculate::check_repeat(const int map_line, string current_string)
{
	for (auto temp_string:word_map[map_line])
	{
		if(current_string.compare(temp_string.get_word()) == 0)
		{
			return false;
		}
	}
	return true;
}

calculate::calculate(vector<string> words, bool more_letter)
{
	for(string s: words)
	{
		//s = to_lower_case(s);
		const auto map_line = ALPHA_TO_INDEX(s[0]);
		if (check_repeat(map_line, s)) {
			word_node current_node(int(s.length()), ALPHA_TO_INDEX(s[s.length() - 1]), s);
			word_map[map_line].push_back(current_node);
		}
	}
	this->more_letter = more_letter;
}

calculate::~calculate()
{
	
}

vector<string> *calculate::get_result()
{
	for (int i = 0; i < ALPHA_COUNT; i++)
	{
		for(auto current_node = word_map[i].begin(); current_node < word_map[i].end(); ++current_node)
		{
			current_word_chain.clear();
			current_letter_count = 0;
			current_word_chain.push_back(current_node->get_word());
			current_letter_count += current_node->get_length();

			current_node->set_used();
			if(!chain_find_next(*current_node))
			{
				//含有单词环，返回空指针
				return nullptr;
			}
			current_node->clear_used();
			//current_word_chain.pop_back();
			//current_letter_count = 0;
		}
	}
	return &longest_word_chain;
}



bool calculate::chain_find_next(word_node prev_node)
{
	vector<word_node> *word_nodes = &word_map[prev_node.get_tail()];
	if(word_nodes->size() == 0)
	{
		check_current_chain();
		return true;
	}
	for(auto current_node = word_nodes->begin(); current_node < word_nodes->end(); ++current_node)
	//for(word_node current_node: word_nodes)
	{
		if(current_node->is_used())
		{
			has_circle = true;
			return false;
		}
		current_word_chain.push_back(current_node->get_word());
		current_letter_count += current_node->get_length();

		current_node->set_used();
		if(!chain_find_next(*current_node))
		{
			return false;
		}
		current_node->clear_used();
		current_word_chain.pop_back();
		current_letter_count-= current_node->get_length();
	}
	return true;
}

void calculate::check_current_chain()
{
	if (!more_letter) {
		if (current_word_chain.size() >= 2 && current_word_chain.size() > longest_word_chain.size()) {
			longest_word_chain = current_word_chain;
			longest_letter_count = current_letter_count;
		}
	}
	else
	{
		if (current_word_chain.size() >= 2 && current_letter_count > longest_letter_count) {
			longest_word_chain = current_word_chain;
			longest_letter_count = current_letter_count;
		}
	}
}
