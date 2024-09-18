#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define int long long

constexpr int MOD = 998244353;

void solve() {
  int n;
  cin >> n;
  vector<int> f(n + 1);
  f[0] = 1;
  for (int i = 1; i <= n; ++i) {
    f[i] = (f[i - 1] * i) % MOD;
  }
  vector<int> a(n);
  map<int, int> b;
  for (auto &x : a) {
    cin >> x;
    ++b[x];
  }
  sort(a.begin(), a.end());
  int ans1 = 0;
  for (int i = 0; i < n; ++i) {
    int mi = 1e14;
    int ma = -1;
    for (int j = i; j < n; ++j) {
      mi = min(a[j], mi);
      ma = max(a[j], ma);
      ans1 += ma - mi;
    }
  }
  int ans2 = 1;
  for (auto [x, cnt] : b) {
    ans2 = (ans2 * f[cnt]) % MOD;
  }
  if (b.size() > 1) {
    ans2 *= 2;
    ans2 %= MOD;
  }
  cout << ans1 << ' ' << ans2 << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
