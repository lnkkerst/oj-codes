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

#define int __int128_t
using ll = long long;

void solve() {
  int n, k;
  ll _n, _k;
  cin >> _n >> _k;
  n = _n, k = _k;
  vector<vector<int>> a(n, vector<int>(3));
  for (auto &v : a) {
    ll t, l, w;
    cin >> t >> l >> w;
    v[0] = t;
    v[1] = l;
    v[2] = w;
  }
  int l = 0, r = 1e24;
  for (int qwq = 1; qwq <= 100; ++qwq) {
    int x = (l + r) / 2;
    int cnt = 0;
    for (auto v : a) {
      int t = v[0] * v[1] + v[2];
      int ct = 0;
      ct += x / t * v[1];
      ct += min((x % t) / v[0], v[1]);
      cnt += ct;
    }
    if (cnt >= k) {
      r = x;
    } else {
      l = x + 1;
    }
  }
  cout << (ll)r << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ll t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
