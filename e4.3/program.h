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

string globalWrapper::_program_name;
string globalWrapper::_version_stamp;
int globalWrapper::_version_number;
int globalWrapper::_tests_run; 
int globalWrapper::_tests_passed;