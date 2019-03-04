#pragma once
#include "calculateInterface.h"
class calculate :
	public calculateInterface
{
public:
	calculate(vector<string> words);
	~calculate();
	vector<string> get_result();
};

