#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> f(n + 1);
	for(int i = 1; i <= n; ++i)
		cin >> f[i];
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		int u = i, tmp = 0;
		while(u != -1) u = f[u], ++tmp;
		ans = max(tmp, ans);
	}
	cout << ans;
	return 0;
}