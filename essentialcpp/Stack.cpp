#include <string>
#include <vector>
#include "Stack.h"

using namespace std;

bool Stack::push(const string& str) {                 //对于类成员函数(暂定)，如果声明和定义分开写，用inline就会报错，若是都写在头文件中，就不会报错
	if (full()) return false;
	_stack.push_back(str);
	return true;
}

bool Stack::pop(string& str) {
	if (empty()) return false;
	str = _stack.back();
	_stack.pop_back();
	return true;
}

bool Stack::peek(string& str) {
	if (empty()) return false;
	str = _stack.back();
	return true;
}