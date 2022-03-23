#include <iostream>
using namespace std;
typedef long long ll;

ll solve(ll x) {
	return x == 1 ? 1 : x * solve(x - 1);
}

int main() {
	ll n;
	cin >> n;
	cout << solve(n);
	return 0;
}