#pragma once
#include <string>
#include <vector>

using namespace std;

class Stack {
public:
	bool push( const string& );
	bool pop( string& );
	bool peek( string& );

	bool empty() { return _stack.empty(); };
	bool full() { return _stack.size() == _stack.max_size(); };

	int size() { return _stack.size(); };

private:
	vector<string> _stack;
};