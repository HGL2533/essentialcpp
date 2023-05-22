#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class UserProfile {
public:
	enum uLevel {Beginner, Intermediate, Advanced, Guru};   //ö���൱�ڶ�����һ����uLevel���͵ı�������������ȡֵֻ���Ǵ��������Ǽ���
	UserProfile();
	UserProfile( string login, uLevel = Beginner );

	bool operator==( const UserProfile& );
	bool operator!=( const UserProfile& );

	//���º�����ȡ����
	string login() const { return _login; }
	string user_name() const { return _user_name; }
	int login_count() const { return _times_logged; }
	int guess_count() const { return _guesses; }
	int guess_correct() const { return _correct_guesses; }
	double guess_average() const;
	string level() const;

	//���º���д������
	void reset_login( const string& val ) { _login = val; }
	void user_name( const string& val ) { _user_name = val; }
	
	void reset_level( const string& val );
	void reset_level( uLevel newlevel ) { _user_level = newlevel; }

	void reset_login_count(int val) { _times_logged = val; }
	void reset_guess_count(int val) { _guesses = val; }
	void reset_guess_correct(int val) { _correct_guesses = val; }

	void bump_login_count(int cnt = 1) { _login += cnt; }                     //cntĬ����1��Ҳ�������û���������޸�
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