#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define int long long

void solve() {
  int n, m;
  cin >> n >> m;
  m *= 2;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
    i *= 2;
  }

  auto calc = [&](vector<int> a) {
    unordered_map<int, int> b;
    int n = a.size();

    function<void(int, int, int)> dfs = [&](int cur, int cnt, int tot) {
      if (b.find(tot) == b.end()) {
        b[tot] = 1e9;
      }
      b[tot] = min(b[tot], cnt);

      if (cur == n) {
        return;
      }

      dfs(cur + 1, cnt, tot);
      dfs(cur + 1, cnt + 1, tot + a[cur] / 2);
      dfs(cur + 1, cnt, tot + a[cur]);
    };
    dfs(0, 0, 0);

    return b;
  };

  int r1 = min(n / 3, (int)8);
  int r2 = min(r1 * 2 + 1, (int)15);

  decltype(a) a1{a.begin(), a.begin() + r1};
  decltype(a) a2{a.begin() + r1, a.begin() + r2};
  decltype(a) a3{a.begin() + r2, a.end()};

  auto b1 = calc(a1);
  auto b2 = calc(a2);
  auto b3 = calc(a3);

  int ans = 1e9;

  // cout << b1.size() << endl;
  // cout << b2.size() << endl;
  // cout << b3.size() << endl;

  for (auto [k1, v1] : b1) {
    for (auto [k2, v2] : b2) {
      int rest = m - (k1 + k2);
      if (b3.find(rest) == b3.end()) {
        continue;
      }
      int v3 = b3[rest];
      ans = min(ans, v1 + v2 + v3);
    }
  }

  if (ans == 1e9) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
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
