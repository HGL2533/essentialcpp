#include <iostream>
#include "mystring.h"
#include "io.h"

using namespace std;
int main()
{
    std::cout << "Hello World!\n";
    Mystring str1;
    Mystring str2("hello!!!!!1!!!!!!");
    Mystring str3(str2);
    str1 = str2;

    cout << str1 << endl;

    
    cout << str2;
}
