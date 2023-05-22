#pragma once
#include <string>

using namespace std;

class globalWrapper {
public:
	static string program_name() { return _program_name; }
	static string version_stamp() { return _version_stamp; }
	static int version_number() { return _version_number; }
	static int tests_run() { return _tests_run; }
	static int tests_passed() { return _tests_passed; }

	static void program_name(const string& npn) { _program_name = npn; }
	static void version_stamp(const string& nstamp) { _version_stamp = nstamp; }
	static void version_number(const int& val) { _version_number = val; }
	static void tests_run(const int val) { _tests_run = val; }
	static void tests_passed(const int val) { _tests_passed = val; }

	globalWrapper() {
		_program_name = "default";
		_version_stamp = "default";
		_version_number = 0;
		_tests_run = 0;
		_tests_passed = 0;
	}

private:
	static string _program_name;
	static string _version_stamp;
	static int _version_number;
	static int _tests_run;
	static int _tests_passed;
};
/*static 成员是与类关联，所有该类的对象共享一份； 其次，static成员必须在类外进行初始化！！*/
/*static修饰的变量先于对象存在，所以static修饰的变量要在类外初始化。因为static是所有对象共享的变量，必须要比对象先存在。*/
/*由于static修饰的类成员属于类，不属于对象，因此static类成员函数是没有this指针的，this指针是指向本对象的指针。正因为没有this指针，所以static类成员函数
不能访问非static的类成员，只能访问 static修饰的类成员。*/
string globalWrapper::_program_name;
string globalWrapper::_version_stamp;
int globalWrapper::_version_number;
int globalWrapper::_tests_run; 
int globalWrapper::_tests_passed;