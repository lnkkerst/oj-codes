#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int t;
	cin >> t;
	unordered_map<char, bool> b;
	// for(auto i : "~!@#$%^") b[i] = 1;
	b['~'] = b['!'] = b['@'] = b['#'] = b['$'] = b['%'] = b['^'] = 1;
	while(t--) {
		string s;
		cin >> s;
		if(s.length() < 8 || s.length() > 16) {
			puts("NO");
			continue;
		}
		bool f1 = 0, f2 = 0, f3 = 0, f4 = 0;
		for(string::iterator i = s.begin(); i != s.end(); ++i) {
			if(isupper(*i)) f1 = 1;
			if(islower(*i)) f2 = 1;
			if(isdigit(*i)) f3 = 1;
			if(b[*i]) f4 = 1;
		}
		if(f1 + f2 + f3 + f4 >= 3) puts("YES");
		else puts("NO");
	}
	return 0;
}