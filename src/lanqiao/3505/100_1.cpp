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
  sort(a.begin(), a.end(), greater<>());
  vector<int> suf(n);
  suf[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    suf[i] = suf[i + 1] + a[i];
  }
  int ans = 1e9;
  function<void(int, int, int)> dfs = [&](int cur, int cnt, int tot) {
    if (tot == m) {
      ans = min(ans, cnt);
      return;
    }
    if (tot > m) {
      return;
    }
    if (cnt >= ans) {
      return;
    }
    if (cur == n - 1) {
      return;
    }
    if (cur >= 0 && tot + suf[cur] < m) {
      return;
    }
    dfs(cur + 1, cnt, tot);
    dfs(cur + 1, cnt + 1, tot + a[cur + 1] / 2);
    dfs(cur + 1, cnt, tot + a[cur + 1]);
  };
  dfs(-1, 0, 0);
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
