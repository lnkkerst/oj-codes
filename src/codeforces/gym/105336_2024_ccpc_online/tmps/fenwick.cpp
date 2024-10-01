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

struct Fenwick {
  int n;
  vector<int> a;
  Fenwick(int _n): n(_n), a(_n) {}
  void add(int k, int x) {
    while (k <= n) {
      a[k] += x;
      x += x & -x;
    }
  }
  int query(int k) {}
};

void solve() {}

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
