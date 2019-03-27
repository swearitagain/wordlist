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

//1. 不存在对应的文件名
//2. 对应文件是一个空文件

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
vector<string> input_output::input(int argc, char * argv[])
{
	//char cmd_in[1000];
	//cin.getline(cmd_in, 1000);
	//string in = string(cmd_in); 

	//int i = 0;
	//while (i < in.size()) {
	//	if (in.at(i) == '-') {
	//		i++; //get next char
	//		char cur = in.at(i);
	//		if (cur == 'w') {
	//			if (is_w) {
	//				throw exception("-w param repeat");
	//			}
	//			is_w = true;
	//		}
	//		else if (cur == 'c') {
	//			if (is_c) {
	//				throw exception("-c param repeat");
	//			}
	//			is_c = true;
	//		}
	//		else if (cur == 'h') {
	//			if (is_h != 0) {
	//				throw exception("-h param repeat");
	//			}
	//			i+=2; //get the blank char
	//			is_h = in.at(i);
	//		}
	//		else if (cur == 't') {
	//			if (is_t != 0) {
	//				throw exception("-t param repeat");
	//			}
	//			i += 2; //get the blank char
	//			is_t = in.at(i);
	//		}
	//		else if (cur == 'r') {
	//			if (is_r) {
	//				throw exception("-r param repeat");
	//			}
	//			is_r = true;
	//		}
	//		else {
	//			throw exception("invalid param");
	//		}
	//	}
	//	else if (in.at(i) != ' ') { //read the absolute path of input file 
	//		break;
	//	}
	//	i++;
	//}
	
	//打开文件,处理字符串
	ifstream in_file;
	vector<string> result;
	//if (argv[0] != "Wordlist.exe") {
	//	ofstream out_file;
	//	out_file.open("test.txt");
	//	out_file << argv[0];
	//	throw exception("第一个参数必须是Wordlist.exe");
	//}
	//对于接下来-参数的判定
	string tmp222 = "";
	int j = 0;
	for (int i = 1; i <  argc; i++) {
		if (argv[i][0] == '-') {
			if (argv[i][1] == 'w') {
				is_w = true;
			}
			else if (argv[i][1] == 'c') {
				is_c = true;
			}
			else if (argv[i][1] == 'h') {
				tmp222 = argv[i + 1];
				//is_h = argv[i+1][0]; //head char
				is_h = tmp222[0];
			}
			else if (argv[i][1] == 't') {
				is_t = argv[i+1][0]; //tail char
			}
			else if (argv[i][1] == 'r') {
				is_r = true;
			}
		}
		else {
			j = i;
			break;
		}
	}
	in_path = "";
	for (int i = j; i < argc - 1; i++) {
		in_path = in_path + argv[i] + " ";
	}
	in_path = in_path + argv[argc - 1];
	//in_path = in.substr(i,in.size());
	//in_path = argv[argc - 2];
	ofstream out_file;
	out_file.open("test.txt");
	out_file << in_path;
	out_file << is_h << endl;
	out_file << is_t << endl;
	out_file << is_w << endl;
	out_file << is_r << endl;
	out_file << is_c << endl;
	for (int i = 0; i < argc; i++) {
		out_file << argv[i] << endl;
	}
	out_file << tmp222 << endl;
	out_file << tmp222[0];

	in_file.open(in_path);
	if (!in_file.is_open()) {
		throw exception("非法输入：文件不存在");
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

//1.接受vector<string>类型单词链
//2.输出到solution.txt
void input_output::output(vector<string> words) {
	ofstream out_file;
	out_file.open(out_path);
	for (int i = 0; i < words.size(); i++) {
		out_file << words.at(i) << endl;
	}
}



