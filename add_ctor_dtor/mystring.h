#pragma once
#include <iostream>

using namespace std;

/*class������point member����һ��Ҫ�п������죬������ֵ������*/

class Mystring {
public:
	Mystring(const char *cstr = 0 );                     //���캯��������char*���߲�������
	Mystring(const Mystring &str);                       //�������캯��
	Mystring& operator=(const Mystring& str);            //������ֵ����
	~Mystring();

	char* get_data() const { return _data; }

private:
	char* _data;
};