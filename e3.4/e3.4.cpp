#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

// ctrl+z 再回车代表EOF
using namespace std;

class even_elem          //函数对象，用于partition方法
{
public:
	bool operator() (int elem) {
		return elem % 2 ? false : true;
	}
};

int main()
{
	vector<int> vec;
	istream_iterator<int> is(cin);
	istream_iterator<int> eof;          //不指定对象则迭代器默认指向 end of file
	copy(is, eof, back_inserter(vec));   //back_inserter很关键，因为vec为空，若是直接copy，用的是赋值运算，会错

	ofstream ofileodd("3.4_odd.txt");
	ofstream ofileeven("3.4_even.txt");
	ostream_iterator<int> odd_it(ofileodd, "\n"), even_it(ofileeven, " ");
	vector<int>::iterator division = stable_partition(vec.begin(), vec.end(), even_elem());
	
	copy(vec.begin(), division, even_it);
	copy(division, vec.end(), odd_it);
}