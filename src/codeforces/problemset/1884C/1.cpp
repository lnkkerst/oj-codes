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

auto myMax(auto x, auto y) { return x > y ? x : y; }

auto solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> a(n);
  for (auto &[l, r] : a) {
    cin >> l >> r;
  }
  auto fn = [&](int p) {
    int res = 0;
    map<int, int> b;
    for (auto &[l, r] : a) {
      if (l <= p && r >= p) {
        continue;
      }
      b[l] += 1;
      b[r + 1] -= 1;
    }
    int cur = 0;
    for (auto [k, v] : b) {
      cur += v;
      res = max(res, cur);
    }
    return res;
  };
  cout << max(fn(1), fn(m)) << endl;
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
