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
	vector<string> get_params(string s); //��ȡ���������룬��ֲ���

	void output();

	vector<string> words;
	bool is_w; //word-����������ͳ��
	bool is_c; //count-����ĸ����ͳ��
	int is_h; //head-ָ������ĸ
	int is_t; //tail-ָ��β��ĸ
	bool is_r; //round-�Ƿ�ɻ�
	string in_path; //�����ļ�·��
	string out_path; //����ļ�·��
	string err_msg;
};

