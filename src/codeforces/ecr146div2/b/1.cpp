#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

#define int long long

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

set<int> book;
int ans;
int maxl;

void calc(int x) {
  int a = sqrt(x);
  int b = x - a * a;
  if (b > a) {
    ++a;
    b = x - a * a;
  }
  cout << a << ' ' << b << ' ' << ans << endl;
  maxl = max(maxl, a);
  ans += a;
  if (b <= 0) {
    return;
  }
  ++ans;
}

void solve() {
  int a, b;
  cin >> a >> b;
  int c = a + b;
  int ans = 2e9;
  for (int i = 1; i * i <= c * 10; ++i) {
    int t = 0;
    t += i - 1;
    t += (a + i - 1) / i;
    t += (b + i - 1) / i;
    ans = min(ans, t);
  }
  cout << ans << endl;
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
