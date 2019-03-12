#pragma once

#include <vector>

#include <string>
using namespace std;

class core
{
//�����װ�˼���ģ�飬ӵ������ӿڣ�����ǰ�����ӿ�Ϊ��׼Ҫ��ӿ�
//�ֱ�Ϊgen_chain, gen_chain_word,gen_chain_char
//wordsΪ����ĵ����б�lenΪ�����б�ĳ��ȣ�result��ŵ�����
//head��tail�ֱ�Ϊ����������ĸ��β��ĸԼ��
//��enable_loopΪtrueʱ��ʾ�������뵥���ı������������ʻ���

//�������ӿ����ƣ�ֻ���������������vector<string>��vector<string>*
public:
	core();
	static void check_head_tail(char head, char tail);
	static void char_star_to_string(char* words[], int len, vector<string> *word_vector);
	static void string_to_char_star(char* result[], vector<string>* result_vector);

	//������൥���������������
	static int gen_chain(char* words[], int len, char* result[]);
	//������൥���������������
	static int gen_chain_word(char* words[], int len, char* result[], char head, char tail, bool enable_loop);
	//���������ĸ�������������
	static int gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop);

	vector<string>* gen_chain_word_v(vector<string> words, char head, char tail, bool enable_loop);

	vector<string>* gen_chain_char_v(vector<string> words, char head, char tail, bool enable_loop);

	~core();
private:

};
