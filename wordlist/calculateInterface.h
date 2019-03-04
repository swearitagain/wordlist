#pragma once
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class calculateInterface
{
public:
	//calculateInterface(vector<string> words);
	virtual ~calculateInterface();

	virtual vector<string> get_result()=0;
}; 
