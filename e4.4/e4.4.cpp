#include <iostream>
#include <string>
#include <vector>
#include "userprofile.h"


/*重载运算符 << */
ostream& operator<<(ostream& os, const UserProfile& rhs)
{
	os << rhs.login() << ' ' << rhs.level() << ' '
		<< rhs.login_count() << ' ' << rhs.guess_count() << ' '
		<< rhs.guess_correct() << ' ' << rhs.guess_average() << endl;
	return os;
}
/*重载运算符 >> */
istream& operator>>(istream& is, UserProfile& rhs)
{
	/* >> 只能通过UserProfile中的reset函数写入数据*/
	string login, level;
	is >> login >> level;

	int lcount, gcount, gcorrect;
	is >> lcount >> gcount >> gcorrect;

	rhs.reset_login(login);
	rhs.reset_level(level);

	rhs.reset_login_count(lcount);
	rhs.reset_guess_count(gcount);
	rhs.bump_guess_correct(gcorrect);

	return is;
}

int main()
{
    std::cout << "Hello World!\n";
    UserProfile anon;
	std::cout << anon << std::endl;

	UserProfile anon_too;
	std::cout << anon_too << std::endl;        //确实生成了不同的标识符


	UserProfile anna("AnnaL", UserProfile::Guru);   //测试构造函数
	cout << anna << endl;                           // another 由于include "UserProfile.h" 这里即使没写命名空间，也行

	//anna.bump_guess_count(27);
	//anna.bump_guess_correct(25);
	//anna.bump_login_count();
	//cout << anna;

	//cin >> anon;
	//cout << anon;
}
