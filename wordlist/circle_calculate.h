#pragma once
#include "specified_calculate.h"
class circle_calculate :
	public specified_calculate
{
public:
	//���캯�����������
	//1. �ַ������飬�����е��ʹ���
	//2. �����������Ƿ�����ĸ�����㵥����
	//3. ���ͣ�ָ������ĸ��-1Ϊ��ָ����0-26��Ӧ26����ĸ
	//4. ���ͣ�ָ��β��ĸ��-1Ϊ��ָ����0-26��Ӧ26����ĸ
	//5. �������ͣ��Ƿ������ı��������ʻ�
	circle_calculate(vector<string> words, bool more_letter, 
		int assigned_initail, int assigned_tail, int circle);
	~circle_calculate();

	bool chain_find_next(word_node prev_node) override;

protected:
	bool circle;
};

