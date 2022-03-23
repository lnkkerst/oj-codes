#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;

signed main() {
	const int INF = 0x7fffffff;
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		int tl = 0, tr = 0, x;
		for(int i = 1; i <= n; ++i) {
			cin >> x;
			tl += x - 1;
			tr += m - x;
		}
		if(n != 1)
			cout << max(((tl - tr) / n) + 1, 1ll) << ' ' << min(m, tl + 1) << endl;
		if(n == 1) cout << x << ' ' << x << endl;
	}
	return 0;
}