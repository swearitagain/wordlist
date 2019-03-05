#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class input_output
{
public:
	input_output();
	~input_output();
	vector<string> input(); 
	vector<string> get_params(string s); //获取命令行输入，拆分参数

	void output(vector<string> words);

	vector<string> words;
	bool is_w; //word-按单词数量统计
	bool is_c; //count-按字母数量统计
	int is_h; //head-指定首字母
	int is_t; //tail-指定尾字母
	bool is_r; //round-是否成环
	string in_path; //输入文件路径
	string out_path; //输出文件路径
	string err_msg;
};

