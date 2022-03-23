#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int n, d;
	cin >> n >> d;
	int ansk = -1, ansx = -1;
	char s[233];
	for(int k = 2; k <= 2333; ++k) {
		itoa(n, s, k);
		int len = strlen(s);
		// cout << s << endl;
		int tmp = 0;
		for(int i = len - 1; i >= 0; --i, ++tmp)
			if(s[i] != d + '0') break;
		if(tmp > ansx) {
			ansk = k;
			ansx = tmp;
		}
	}
	cout << ansk << ' ' << ansx;
	return 0;
}