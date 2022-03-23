
#include <bits/stdc++.h>
#define int long long
#define ll long long
const int mod = 1e9 + 7;
ll fpow(ll a, ll k)
{
	ll ret = 1;
	while (k)
	{
		if (k & 1)
		{
			ret *= a;
			ret %= mod;
		}
		k >>= 1;
		a = a * a;
		a %= mod;
	}
	return ret % mod;
}
int exgcd(int a, int b, int &x, int &y)
{
	if (b == 0)
		return x = 1, y = 0, a;
	int r = exgcd(b, a % b, x, y);
	int t = x;
	x = y;
	y = t - (a / b) * y;
	return r;
}

ll calc(ll a, ll b)
{
	ll x, y;
	exgcd(b, mod, x, y);
	x *= a;
	x = (x % mod + mod) % mod;
	return x;
}
inline ll inv(int x)
{
	return fpow(x, mod - 2) % mod;
}
signed main()
{
	using namespace std;
	ll n, k;
	cin >> n >> k;
	ll ans = fpow(n - 1, k - 1);
	ans -= fpow(-1, k - 1);
	ans %= mod;
	ans *= n - 1;
	ans %= mod;
	ans *= inv(n);
	ans %= mod;
	// cout << (ans * inv(fpow(n - 1, k))) % mod;
	cout << calc(ans, fpow(n - 1, k));
}