#include "mystring.h"
#include <cstring>
using namespace std;

/*  strlen 函数接受一个char*指针，从指针开始遍历，遇到'\0'时视为字符串结束，故能得到字符串长度(不包括'\0')   */


/*对于inline，若成员函数在.h文件外实现，则不能加上，否则报错； 在.h文件内实现，则可以加上*/

Mystring::Mystring(const char* cstr) {    //默认构造函数
	if (cstr) {
		_data = new char[strlen(cstr) + 1];
		strcpy(_data, cstr);
	}
	else {
		_data = new char[1];
		*_data = '\0';
	}
}


Mystring::~Mystring() {            //析构函数
	delete[] _data;
}


Mystring::Mystring(const Mystring& str) {                  //拷贝构造
	_data = new char[strlen(str._data) + 1];
	strcpy(_data, str._data);
}


Mystring& Mystring::operator=(const Mystring& str) {       //拷贝赋值
	if (this == &str)
		return *this;
	delete[] _data;
	new char[strlen(str._data) + 1];
	strcpy(_data, str._data);
	return *this;
}

