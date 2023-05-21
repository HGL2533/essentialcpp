#include <iostream>
#include <vector>
#include "Stack.h"
using namespace std;

int main() {
	Stack st;
	string str;

	while (cin >> str && !st.full()) {
		st.push(str);
	}

	if (st.empty()) {
		cout << "no string were read!" << endl;
		return 0;
	}

	st.peek(str);
	if (st.size() == 1 && str.empty()) {
		cout << "no strings were read" << endl;
		return 0;
	}

	cout << "read in " << st.size() << "strings" << endl;
	cout << "the strings, in reverse order: " << endl;

	while (st.size()) {
		if (st.pop(str))
			cout << str << " ";
	}
	cout << "\n";
	cout << "there are " << st.size() << "elements in st!" << endl;
}