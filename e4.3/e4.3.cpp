#include <iostream>
#include "program.h"

using namespace std;
int main()
{
    globalWrapper gw;
    gw.program_name("test");
    cout << gw.program_name() << endl;;
    cout << gw.version_stamp() << endl;
    cout << gw.version_number();
}
