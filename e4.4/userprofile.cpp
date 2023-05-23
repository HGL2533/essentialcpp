#include "userprofile.h"

using namespace std;

map<string, UserProfile::uLevel> UserProfile::_level_map;                /*对于static类型的成员变量，class内是声明，还需要在cpp文件中进行定义*/


void UserProfile::init_level_map()
{
	_level_map["Beginner"] = Beginner;
	_level_map["Intermediate"] = Intermediate;
	_level_map["Advanced"] = Advanced;
	_level_map["Guru"] = Guru;
}

/*根据传入的level字符串，修改对象的level(枚举型)*/
void UserProfile::reset_level(const string& level)
{
	map<string, UserProfile::uLevel>::iterator it;
	if (_level_map.empty())
		init_level_map(); 
	_user_level = ((it = _level_map.find(level)) != _level_map.end()) ? it->second : Beginner;
}

