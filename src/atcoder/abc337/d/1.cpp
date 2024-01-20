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

constexpr int INT_MAX = 1e9;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> a(n);
  int ans = INT_MAX;
  auto calc = [&](vector<int> a) {
    int n = a.size();
    int su = 0;
    int l = 0;
    int res = INT_MAX;
    for (int r = 0; r < n; ++r) {
      su += a[r];
      while (r - l + 1 >= k) {
        res = min(res, su);
        su -= a[l];
        ++l;
      }
    }
    return res;
  };
  auto proc = [&](string s) {
    vector<int> cur;
    for (auto i : s) {
      if (i == 'x') {
        ans = min(calc(cur), ans);
        cur.clear();
        continue;
      }
      if (i == '.') {
        cur.emplace_back(1);
      } else {
        cur.emplace_back(0);
      }
    }
    if (!cur.empty()) {
      ans = min(ans, calc(cur));
    }
  };
  for (auto &i : a) {
    cin >> i;
    proc(i);
  }
  for (int i = 0; i < m; ++i) {
    string s = "";
    for (int j = 0; j < n; ++j) {
      s += a[j][i];
    }
    proc(s);
  }
  cout << (ans == INT_MAX ? -1 : ans) << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
}
