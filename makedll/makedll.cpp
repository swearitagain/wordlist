// makedll.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "core.h"

//#ifdef MAKEDLL_EXPORTS
//#define MAKEDLL_API __declspec(dllexport)
//#else
//#define MAKEDLL_API __declspec(dllimport)
//#endif

//extern "C" MAKEDLL_API core* _stdcall CreateExportObj();
//extern "C" MAKEDLL_API void _stdcall DestroyExportObj(core* mycore);
extern "C"
{
	int __declspec(dllexport) gen_chain(char* words[], int len, char* result[])
	{
		return core::gen_chain(words, len, result);
	}

	int __declspec(dllexport) gen_chain_word(char* words[], int len, char* result[], char head, char tail, bool enable_loop)
	{
		return core::gen_chain_word(words, len, result, head, tail, enable_loop);
	}

	int __declspec(dllexport) gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop)
	{
		return core::gen_chain_char(words, len, result, head, tail, enable_loop);
	}

	vector<string> __declspec(dllexport) * gen_chain_word_v(vector<string> words, char head, char tail, bool enable_loop)
	{
		return core::gen_chain_word_v(words, head, tail, enable_loop);
	}
	vector<string> __declspec(dllexport) * gen_chain_char_v(vector<string> words, char head, char tail, bool enable_loop)
	{
		return core::gen_chain_char_v(words, head, tail, enable_loop);
	}
}