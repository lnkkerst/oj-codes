#pragma GCC optimize(2)
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

signed main() {
	int n, d;
	cin >> n >> d;
	int ansk = -1, ansx = -1;
	for(int k = 2; k * k <= (n - d); ++k) {
		vector<int> s;
		int t = n;
		while(t) {
			s.push_back(t % k);
			t /= k;
		}
		int tmp = 0;
		for(auto i : s) {
			if(i != d) break;
			++tmp;
		}
		if(tmp > ansx) {
			ansk = k;
			ansx = tmp;
		}
	}
	cout << ansk << ' ' << ansx;
	return 0;
}