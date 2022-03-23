#include <iostream>
using namespace std;

string str, fr, ba;
int n;
bool fl;

int main() {
	cin >> str >> n;
	for(int i = 1; i <= n; ++i) {
		int opt;
		cin >> opt;
		if(opt == 1) fl = !fl;
		if(opt == 2) {
			int pos;
			char ch;
			cin >> pos >> ch;
			(pos == 2) && (pos = 0);
			if(pos ^ fl) ba += ch;
			else fr += ch;
		}
	}
	if(!fl) {
		for(auto i = ba.rbegin(); i != ba.rend(); ++i)
			cout << *i;
		for(auto i = str.rbegin(); i != str.rend(); ++i)
			cout << *i;
		cout << fr;
	}
	else {
		for(auto i = fr.rbegin(); i != fr.rend(); ++i)
			cout << *i;
		cout << str << ba;
	}
	return 0;
}