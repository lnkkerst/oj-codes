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
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  Fenwick tr(n);
  int ans = 0;
  vector<int> inc(n + 2, -1);
  for (int i = 1; i <= n; ++i) {
    ans += tr.query(a[i], n);
    tr.add(a[i], 1);
    if (inc[a[i] + 1] == 0) {
      inc[a[i]] = 1;
      --ans;
    } else {
      inc[a[i]] = 0;
    }
  }
  cout << ans << endl;
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
