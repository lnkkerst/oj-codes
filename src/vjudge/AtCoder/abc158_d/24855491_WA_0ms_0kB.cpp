#include <iostream>
#include <queue>
using namespace std;

string str;
deque<char > a;
int n;
bool fl = 0;

int main() {
	cin >> str >> n;
	for(auto i : str) a.push_back(i);
	for(int i = 1; i <= n; ++i) {
		int opt;
		cin >> opt;
		if(opt == 1) fl = !fl;
		if(opt == 2) {
			int pos;
			char ch;
			cin >> pos >> ch;
			(pos == 2) && (pos = 0);
			if(pos ^ fl) a.push_back(ch);
			else a.push_front(ch);
		}
	}
	if(fl) for(auto i : a) cout << i;
	else for(auto i = a.rbegin(); i != a.rend(); ++i)
		cout << *i;
	return 0;
}