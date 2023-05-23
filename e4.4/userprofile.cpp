#include "userprofile.h"

using namespace std;

map<string, UserProfile::uLevel> UserProfile::_level_map;                /*����static���͵ĳ�Ա������class��������������Ҫ��cpp�ļ��н��ж���*/


void UserProfile::init_level_map()
{
	_level_map["Beginner"] = Beginner;
	_level_map["Intermediate"] = Intermediate;
	_level_map["Advanced"] = Advanced;
	_level_map["Guru"] = Guru;
}

/*���ݴ����level�ַ������޸Ķ����level(ö����)*/
void UserProfile::reset_level(const string& level)
{
	map<string, UserProfile::uLevel>::iterator it;
	if (_level_map.empty())
		init_level_map(); 
	_user_level = ((it = _level_map.find(level)) != _level_map.end()) ? it->second : Beginner;
}

