#pragma once
#include <iostream>

using namespace std;

/*class若带有point member，则一定要有拷贝构造，拷贝赋值，析构*/

class Mystring {
public:
	Mystring(const char *cstr = 0 );                     //构造函数，传入char*或者不传参数
	Mystring(const Mystring &str);                       //拷贝构造函数
	Mystring& operator=(const Mystring& str);            //拷贝赋值函数
	~Mystring();

	char* get_data() const { return _data; }

private:
	char* _data;
};