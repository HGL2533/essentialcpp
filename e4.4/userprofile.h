#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class UserProfile {
public:
	enum uLevel {Beginner, Intermediate, Advanced, Guru};   //枚举相当于定义了一个叫uLevel类型的变量，不过他的取值只能是大括号里那几种
	UserProfile();
	UserProfile( string login, uLevel = Beginner );

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

	void bump_login_count(int cnt = 1) { _login += cnt; }                     //cnt默认是1，也可以由用户传入参数修改
	void bump_guess_count(int cnt = 1) { _guesses += cnt; }
	void bump_guess_correct(int cnt = 1) { _correct_guesses += cnt; }

private:
	string _login;
	string _user_name;
	int _times_logged;
	int _guesses;
	int _correct_guesses;
	uLevel _user_level;

};