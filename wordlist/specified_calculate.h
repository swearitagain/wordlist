#pragma once
#include "calculate.h"
class specified_calculate :
	public calculate
{
public:
	//���캯���ĸ�������
	//1. �ַ������飬�����е��ʹ���
	//2. �����������Ƿ�����ĸ�����㵥����
	//3. ���ͣ�ָ������ĸ��-1Ϊ��ָ����0-26��Ӧ26����ĸ
	//4. ���ͣ�ָ��β��ĸ��-1Ϊ��ָ����0-26��Ӧ26����ĸ
	specified_calculate(vector<string> words, bool more_letter, int assigned_initail, int assigned_tail);
	~specified_calculate();
	vector<string> *get_result() override;
	void check_current_chain() override;

private:
	int assigned_initial;
	int assigned_tail;
};

