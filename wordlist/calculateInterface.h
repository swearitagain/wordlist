#pragma once
#include <vector>
#include <string>

using namespace std;

class calculateInterface
{
public:
	//calculateInterface(vector<string> words);
	virtual ~calculateInterface();
	
	//得到结果，返回一个指向vector<string>的指针，vector中含有结果单词链
	//如果含有单词环而不允许（不含-r参数），则返回空指针
	virtual vector<string> *get_result()=0;
};

inline calculateInterface::~calculateInterface()
{
	return;
} 
