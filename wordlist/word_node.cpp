#include "pch.h"
#include "word_node.h"


word_node::word_node(int length, int tail, string word)
{
	this->length = length;
	this->tail = tail;
	this->used = false;
	this->word = word;
}

int word_node::get_length() const
{
	return length;
}

int word_node::get_tail() const
{
	return tail;
}

string word_node::get_word() const
{
	return word;
}

bool word_node::is_used()
{
	return used;
}

void word_node::set_used()
{
	used = true;
}

void word_node::clear_used()
{
	used = false;
}
