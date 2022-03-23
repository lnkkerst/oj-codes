#include <iostream>
#define int long long
using namespace std;

signed main() {
	int n, a, b;
	cin >> n >> a >> b;
	int ans = n / (a + b);
	n %= a + b;
	ans *= a;
	ans += min(a, n);
	cout << ans;
	return 0;
}