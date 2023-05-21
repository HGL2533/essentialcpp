#include <string>
#include <vector>
#include "Stack.h"

using namespace std;

bool Stack::push(const string& str) {                 //�������Ա����(�ݶ�)����������Ͷ���ֿ�д����inline�ͻᱨ�����Ƕ�д��ͷ�ļ��У��Ͳ��ᱨ��
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