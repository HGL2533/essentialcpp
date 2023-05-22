#include "mystring.h"
#include <cstring>
using namespace std;

/*  strlen ��������һ��char*ָ�룬��ָ�뿪ʼ����������'\0'ʱ��Ϊ�ַ������������ܵõ��ַ�������(������'\0')   */


/*����inline������Ա������.h�ļ���ʵ�֣����ܼ��ϣ����򱨴� ��.h�ļ���ʵ�֣�����Լ���*/

Mystring::Mystring(const char* cstr) {    //Ĭ�Ϲ��캯��
	if (cstr) {
		_data = new char[strlen(cstr) + 1];
		strcpy(_data, cstr);
	}
	else {
		_data = new char[1];
		*_data = '\0';
	}
}


Mystring::~Mystring() {            //��������
	delete[] _data;
}


Mystring::Mystring(const Mystring& str) {                  //��������
	_data = new char[strlen(str._data) + 1];
	strcpy(_data, str._data);
}


Mystring& Mystring::operator=(const Mystring& str) {       //������ֵ
	if (this == &str)
		return *this;
	delete[] _data;
	new char[strlen(str._data) + 1];
	strcpy(_data, str._data);
	return *this;
}

