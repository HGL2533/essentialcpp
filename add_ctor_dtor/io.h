#pragma once
#include <iostream>
#include "mystring.h"


/*���� << �������ע�� << ����һ��������class�ĳ�Ա��������Ϊ����Ա�����Ļ� */
/*ʹ�� << �����෴�������ostrean�����Ҷ�����Ҫ����Ķ���*/

ostream& operator<<(ostream& os, const Mystring& str) {
    os << str.get_data();
    return os;
}