#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>

using namespace std;

class UserProfile {
public:
	enum uLevel {Beginner, Intermediate, Advanced, Guru};   //枚举相当于定义了一个叫uLevel类型的变量，不过他的取值只能是大括号里那几种
	UserProfile();
	UserProfile( string login, uLevel level = Beginner );        //这里去掉level？

	bool operator==( const UserProfile& );
	bool operator!=( const UserProfile& );

	//以下函数读取数据
	string login() const { return _login; }
	string user_name() const { return _user_name; }
	int login_count() const { return _times_logged; }
	int guess_count() const { return _guesses; }
	int guess_correct() const { return _correct_guesses; }
	double guess_average() const;
	string level() const;

	//以下函数写入数据
	void reset_login( const string& val ) { _login = val; }
	void user_name( const string& val ) { _user_name = val; }
	
	void reset_level( const string& val );
	void reset_level( uLevel newlevel ) { _user_level = newlevel; }

	void reset_login_count(int val) { _times_logged = val; }
	void reset_guess_count(int val) { _guesses = val; }
	void reset_guess_correct(int val) { _correct_guesses = val; }

	void bump_login_count(int cnt = 1) { _times_logged += cnt; }                     //cnt默认是1，也可以由用户传入参数修改
	void bump_guess_count(int cnt = 1) { _guesses += cnt; }
	void bump_guess_correct(int cnt = 1) { _correct_guesses += cnt; }

private:
	string _login;
	string _user_name;
	int _times_logged;
	int _guesses;
	int _correct_guesses;
	uLevel _user_level;

	static map<string, uLevel> _level_map;                                        //static类型的成员变量，class内是声明，还需在类外定义！
	static void init_level_map();
	static string guest_login;
};

/*求平均猜测次数*/
inline
double UserProfile::guess_average() const
{
	return _guesses ? double(_correct_guesses) / double(_guesses) * 100 : 0.0;
}

/*level函数将枚举类型的level转换为字符串*/
inline
string UserProfile::level() const
{
	static string _level_table[] = { "Beginner", "Intermediate", "Advanced", "Guru" };
	return _level_table[_user_level];                 //枚举类型的_user_level实际上是 0~3 的值
}

/*默认的匿名构造函数以及生成唯一的用户标识*/
inline
UserProfile::UserProfile()
	:_login("guest"), _user_level(Beginner), _times_logged(1), _guesses(0), _correct_guesses(0)
{
	static int id = 0;       //这里static很关键，保证了所有对象共享 id 这个变量，每次声明一个对象就调用构造函数，id++确保标识的独一无二
	char buf[16];
	_itoa_s(id++, buf, 10);   //将int型的id转换为字符，存放在buf中
	_login += buf;           //+=是string类型重载过，表示字符串的连接，依次生成 guest0， guest1，guest2这样的字符串
}

/*构造函数(非匿名)，接受两个参数，有login说明不是第一次登录，无需生成用户标识login*/
inline
UserProfile::UserProfile(string login, uLevel level)          //默认值放在声明处而不是定义处
	:_login(login), _user_level(level), _times_logged(1), _guesses(0), _correct_guesses(0) {}

/*重载运算符 ==*/
inline bool
UserProfile::operator==(const UserProfile& rhs)
{
	if (rhs._user_name == _user_name && rhs._login == _login)
		return true;
	return false;
}

/*重载运算符 != , 利用了重载之后的 ==*/
inline bool
UserProfile::operator!=(const UserProfile& rhs)
{
	return !(*this == rhs);
}




/*如果有多个源文件包含了这个头文件，那么这些源文件都会定义一个相同的静态成员变量，这会导致重定义错误*/
// map<string, UserProfile::uLevel> UserProfile::_level_map;        不能在这里定义static成员变量！！