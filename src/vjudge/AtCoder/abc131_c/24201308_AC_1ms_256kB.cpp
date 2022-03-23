#include <iostream>
using namespace std;
#define int long long

int l, r, a, b;

int gcd(int x, int y) {
	return !y ? x : gcd(y, x % y);
}

int lcm(int x, int y) {
	return x * y / gcd(x, y);
}

signed main() {
	cin >> l >> r >> a >> b;
	int t = lcm(a, b);
	int ans = r - l + 1;
	ans -= (r) / a - (l - 1) / a;
	ans -= (r) / b - (l - 1) / b;
	ans += (r) / t - (l - 1) / t;
	cout << ans;
	return 0;
}