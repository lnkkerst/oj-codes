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
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  map<int, map<int, int>> b;
  for (auto &[r, c] : a) {
    cin >> r >> c;
    ++b[c][r];
  }
  auto calc = [](vector<pair<int, int>> a) {
    map<int, map<int, int>> b;
    for (auto &[r, c] : a) {
      ++b[c][r];
    }
    bool fll = false, flr = false;
    bool fl2l = false, fl2r = false;
    for (auto [c, r] : b) {
      if (c < 0) {
        fl2l = true;
        if (c != 0) {
          if (r[1] && r[2]) {
            fll = true;
          }
          if (r[1] && b[c + 1][2]) {
            fll = true;
          }
          if (r[2] && b[c + 1][1]) {
            fll = true;
          }
        }
      }
      if (c > 0) {
        fl2r = true;
        if (c != 0) {
          if (r[1] && r[2]) {
            flr = true;
          }
          if (r[1] && b[c - 1][2]) {
            flr = true;
          }
          if (r[2] && b[c - 1][1]) {
            flr = true;
          }
        }
      }
    }
    int ans = 4;
    if (fll) {
      ans -= 2;
    } else if (fl2l) {
      ans--;
    }
    if (flr) {
      ans -= 2;
    } else if (fl2r) {
      ans--;
    }
    ans = min(ans, 3ll);
    if (b[-1][1] || b[1][1]) {
      ans = min(ans, 2ll);
    }
    if (b[-1][1] && b[1][1]) {
      ans = min(ans, 1ll);
    }
    return ans;
  };
  int ans = 3;
  ans = min(ans, calc(a));
  if (!b[0][2]) {
    a.emplace_back(2, 0);
    ans = min(ans, calc(a) + 1);
    a.pop_back();
  }
  if (!b[-1][1]) {
    a.emplace_back(1, -1);
    ans = min(ans, calc(a) + 1);
    a.pop_back();
  }
  if (!b[1][1]) {
    a.emplace_back(1, 1);
    ans = min(ans, calc(a) + 1);
    a.pop_back();
  }
  if (!b[1][1] && !b[-1][1]) {
    a.emplace_back(1, 1);
    a.emplace_back(1, -1);
    ans = min(ans, calc(a) + 2);
    a.pop_back();
    a.pop_back();
  }
  if (!b[1][1] && !b[0][2]) {
    a.emplace_back(1, 1);
    a.emplace_back(2, 0);
    ans = min(ans, calc(a) + 2);
    a.pop_back();
    a.pop_back();
  }
  if (!b[-1][1] && !b[0][2]) {
    a.emplace_back(1, -1);
    a.emplace_back(2, 0);
    ans = min(ans, calc(a) + 2);
    a.pop_back();
    a.pop_back();
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
