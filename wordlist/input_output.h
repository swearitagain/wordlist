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

	vector<string> input(int argc, char * argv[]);
	void output(vector<string> words);

	vector<string> words;
	bool is_w; //word-����������ͳ��
	bool is_c; //count-����ĸ����ͳ��
	char is_h; //head-ָ������ĸ
	char is_t; //tail-ָ��β��ĸ
	bool is_r; //round-�Ƿ�ɻ�
	string in_path; //�����ļ�·��
	string out_path; //����ļ�·��
	string err_msg; //������־
};

