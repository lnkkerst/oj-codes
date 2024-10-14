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

inline constexpr int MOD = 998244353;

struct Fenwick {
  int n;
  vector<int> a;
  Fenwick(int _n): n(_n + 10), a(_n + 10) {}
  void add(int k, int x) {
    while (k <= n) {
      a[k] += x;
      k += k & -k;
    }
  }
  int query(int k) {
    int res = 0;
    while (k > 0) {
      res += a[k];
      k -= k & -k;
    }
    return res;
  }
  int query(int l, int r) {
    return query(r) - query(l - 1);
  }
};

void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  vector<int> s;
  for (auto &[l, r] : a) {
    cin >> l >> r;
    s.emplace_back(l);
    s.emplace_back(r);
  }
  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()), s.end());
  unordered_map<int, int> id;
  int cid = 0;
  for (auto x : s) {
    id[x] = ++cid;
  }
  int ma = cid;
  for (auto &[l, r] : a) {
    l = id[l];
    r = id[r];
  }
  sort(a.begin(), a.end());
  int ans = 1;
  Fenwick tr(ma + 10);
  for (auto [l, r] : a) {
    int cnt = tr.query(l, ma);
    if (cnt >= k) {
      cout << 0 << endl;
      return;
    }
    ans *= k - cnt;
    ans %= MOD;
    tr.add(r, 1);
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
