#pragma once
#include <vector>
#include <string>

using namespace std;

class calculateInterface
{
public:
	//calculateInterface(vector<string> words);
	virtual ~calculateInterface();
	
	//�õ����������һ��ָ��vector<string>��ָ�룬vector�к��н��������
	//������е��ʻ�������������-r���������򷵻ؿ�ָ��
	virtual vector<string> *get_result()=0;
};

inline calculateInterface::~calculateInterface()
{
	return;
} 
