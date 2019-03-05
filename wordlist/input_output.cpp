#include "pch.h"
#include "input_output.h"

using namespace std;

input_output::input_output()
{
	is_w = false;
	is_c = false;
	is_h = false;
	is_t = false;
	is_r = false;
	out_path = "solution.txt";
}

input_output::~input_output()
{

}


//1.从命令行接受输入-w absolute_path_of_word_list
//2.解析出-w，并且从绝对路径打开文件，提取文件中的单词
//3.将单词以vector<string>形式返回

//错误分类：
//1. 无效的命令 abcd
//2. 错误的参数 -ww absolute_path_of_word_list
//3. 错误的参数组合 -c -w -t
//4. 错误的文件格式 xxx.xlsx
//5. 命令参数是大写，转换为小写后是有效命令 [?] 

//错误处理
//1.直接从命令行输出提示
//2.保证任何情况下程序不崩溃

//-w absolute_path_of_word_list
//-c absolute_path_of_word_list
//-r -w absolute_path_of_word_list
//-h e -w absolute_path_of_word_list
//-t t -w absolute_path_of_word_list
//-h e -t t -w absolute_path_of_word_list
//-r -h e -t t -w absolute_path_of_word_list
//‪-h e -w ‪E:\软件工程\test_case1.txt
vector<string> input_output::input() {
	char cmd_in[1000];
	cin.getline(cmd_in, 1000);
	string in = string(cmd_in); 

	int i = 0;
	while (i < in.size()) {
		if (in.at(i) == '-') {
			i++; //get next char
			char cur = in.at(i);
			if (cur == 'w') {
				if (is_w) {
					err_msg = "-w param repeat"; break;
				}
				is_w = true;
			}
			else if (cur == 'c') {
				if (is_c) {
					err_msg = "-c param repeat"; break;
				}
				is_c = true;
			}
			else if (cur == 'h') {
				if (is_h != 0) {
					err_msg = "-h param repeat"; break;
				}
				i+=2; //get the blank char
				is_h = in.at(i) - 'a';
			}
			else if (cur == 't') {
				if (is_t != 0) {
					err_msg = "-t param repeat"; break;
				}
				i += 2; //get the blank char
				is_t = in.at(i) - 'a';
			}
			else if (cur == 'r') {
				if (is_r) {
					err_msg = "-r param repeat"; break;
				}
			}
			else {
				err_msg = "invalid param"; break;
			}
		}
		else if (in.at(i) != ' ') { //read the absolute path of input file 
			break;
		}
		i++;
	}
	
	//打开文件逻辑
	ifstream in_file;
	vector<string> result;
	in_path = in.substr(i,in.size());
	in_file.open(in_path);
	if (!in_file.is_open()) {
		//TODO 打不开文件
	}
	char c;
	string tmp;
	in_file >> noskipws;
	while (!in_file.eof()) {
		string tmp;
		bool is_word = false;
		in_file >> c;

		while ( ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) && !in_file.eof()) {
			tmp += c;
			in_file >> c;
			is_word = true;
		}
		if(is_word)
			result.push_back(tmp);
	}
	in_file.close();
	return result;
}

vector<string> input_output::get_params(string s)
{
	return vector<string>();
}

vector<string> split(const string &s, const string &seperator) {
	vector<string> result;
	

	return result;
}



//1.接受vector<string>类型单词链
//2.输出到solution.txt
void input_output::output() {

}
