#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;
	string res;
	for(auto i = str.rbegin(); i != str.rend(); ++i)
		res += *i;
	cout << res;
	return 0;
}