#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct Fenwick {
  int n;
  vector<int> a;
  Fenwick(int _n) : n(_n), a(_n + 10) {
  }
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
