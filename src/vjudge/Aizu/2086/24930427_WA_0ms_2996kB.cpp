#include <iostream>
#define int long long
using namespace std;

int n, m;
string s;

int qpow(int x, int k, int MOD = 1e9 + 7) {
  int ret = 1;
  while (k) {
    if (k & 1)
      ret *= x;
    x *= x, k >>= 1;
    x % MOD, ret %= MOD;
  }
  return ret;
}

int pre(char x) {
  if (isdigit(x))
    return x - '0';
  return x - 'A' + 10;
}

int calc(int x, int y) {
  int ret = 0;
  while (x)
    ret += x / y, x /= y;
  return ret;
}

signed main() {
  cin >> m >> s;
  for (int i = 0; i < (int)s.length(); ++i)
    n += pre(s[i]) * qpow(m, (int)s.length() - i - 1);
  int ans = 2e18;
  for (int i = 2; i * i <= m; ++i) {
    int cnt = 0;
    while (m % i == 0)
      ++cnt, m /= i;
    if (cnt)
      ans = min(ans, calc(n, i) / cnt);
  }
  if (m > 1)
    ans = min(ans, calc(n, m));
  cout << ans;
  return 0;
}