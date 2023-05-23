#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>

using namespace std;

class UserProfile {
public:
	enum uLevel {Beginner, Intermediate, Advanced, Guru};   //ö���൱�ڶ�����һ����uLevel���͵ı�������������ȡֵֻ���Ǵ��������Ǽ���
	UserProfile();
	UserProfile( string login, uLevel level = Beginner );        //����ȥ��level��

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

	void bump_login_count(int cnt = 1) { _times_logged += cnt; }                     //cntĬ����1��Ҳ�������û���������޸�
	void bump_guess_count(int cnt = 1) { _guesses += cnt; }
	void bump_guess_correct(int cnt = 1) { _correct_guesses += cnt; }

private:
	string _login;
	string _user_name;
	int _times_logged;
	int _guesses;
	int _correct_guesses;
	uLevel _user_level;

	static map<string, uLevel> _level_map;                                        //static���͵ĳ�Ա������class�������������������ⶨ�壡
	static void init_level_map();
	static string guest_login;
};

/*��ƽ���²����*/
inline
double UserProfile::guess_average() const
{
	return _guesses ? double(_correct_guesses) / double(_guesses) * 100 : 0.0;
}

/*level������ö�����͵�levelת��Ϊ�ַ���*/
inline
string UserProfile::level() const
{
	static string _level_table[] = { "Beginner", "Intermediate", "Advanced", "Guru" };
	return _level_table[_user_level];                 //ö�����͵�_user_levelʵ������ 0~3 ��ֵ
}

/*Ĭ�ϵ��������캯���Լ�����Ψһ���û���ʶ*/
inline
UserProfile::UserProfile()
	:_login("guest"), _user_level(Beginner), _times_logged(1), _guesses(0), _correct_guesses(0)
{
	static int id = 0;       //����static�ܹؼ�����֤�����ж����� id ���������ÿ������һ������͵��ù��캯����id++ȷ����ʶ�Ķ�һ�޶�
	char buf[16];
	_itoa_s(id++, buf, 10);   //��int�͵�idת��Ϊ�ַ��������buf��
	_login += buf;           //+=��string�������ع�����ʾ�ַ��������ӣ��������� guest0�� guest1��guest2�������ַ���
}

/*���캯��(������)������������������login˵�����ǵ�һ�ε�¼�����������û���ʶlogin*/
inline
UserProfile::UserProfile(string login, uLevel level)          //Ĭ��ֵ���������������Ƕ��崦
	:_login(login), _user_level(level), _times_logged(1), _guesses(0), _correct_guesses(0) {}

/*��������� ==*/
inline bool
UserProfile::operator==(const UserProfile& rhs)
{
	if (rhs._user_name == _user_name && rhs._login == _login)
		return true;
	return false;
}

/*��������� != , ����������֮��� ==*/
inline bool
UserProfile::operator!=(const UserProfile& rhs)
{
	return !(*this == rhs);
}




/*����ж��Դ�ļ����������ͷ�ļ�����ô��ЩԴ�ļ����ᶨ��һ����ͬ�ľ�̬��Ա��������ᵼ���ض������*/
// map<string, UserProfile::uLevel> UserProfile::_level_map;        ���������ﶨ��static��Ա��������