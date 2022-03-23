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
		vector<int > a;
		for(int i = 1; i <= n; ++i) {
			int x;
			cin >> x;
			a.push_back(x);
		}
		vector<int> a1(m), a2(m);
		int tmp = 0;
		for(auto i : a) {
			sort(a1.begin(), a1.end());
			sort(a2.begin(), a2.end(), greater<int>());
			for(int j = 0; j < i - 1; ++j)
				a1[j] += INF + 1, a2[j] += INF + 1;
			tmp += i - 1;
		}
		sort(a1.begin(), a1.end());
		sort(a2.begin(), a2.end());
		// for(auto i : a1) {
		// 	cout << i << ' ';
		// }
		// cout << endl;
		// for(auto i : a2) {
		// 	cout << i << ' ';
		// }
		// cout << endl;
		auto al = upper_bound(a1.begin(), a1.end(), INF * n);
		if(al == a1.end()) cout << 1 << ' ';
		else cout << a1.size() - (al - a1.begin()) + 1 << ' ';
		cout << min(m, tmp + 1) << endl;
		// al = upper_bound(a2.begin(), a2.end(), n);
		// if(al == a2.end()) cout << 1 << endl;
		// else cout << a2.size() - (al - a2.begin()) + 1 << endl;

	}
	return 0;
}