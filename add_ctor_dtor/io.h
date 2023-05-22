#pragma once
#include <iostream>
#include "mystring.h"


/*重载 << 运算符，注意 << 重载一定不能是class的成员函数，因为，成员函数的话 */
/*使用 << 会变得相反，左端是ostrean对象，右端是想要输出的对象*/

ostream& operator<<(ostream& os, const Mystring& str) {
    os << str.get_data();
    return os;
}