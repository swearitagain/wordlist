#pragma once
#include <string>

using namespace std;
//����������
class word_node
{
public:
	word_node(int length, int tail, string word);
	int get_length() const;
	int get_tail() const;
	string get_word() const;
	bool is_used();
	void set_used();
	void clear_used();

	string word;
	int length;	//���ʳ���
	int tail;	//����β��ĸ����Ӧ���
	bool used;	//�����Ƿ��ڱ��������б�ʹ�ù�

};