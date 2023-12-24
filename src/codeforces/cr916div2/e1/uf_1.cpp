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
  vector<int> a(n), b(n);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &i : b) {
    cin >> i;
  }
  vector<int> ans;
  function<pair<int, int>(int, vector<int>, vector<int>)> dfs =
      [&](int cur, vector<int> a, vector<int> b) -> pair<int, int> {
    if (cur == n) {
      int t = (accumulate(a.begin(), a.end(), 0ll) -
               accumulate(b.begin(), b.end(), 0ll));
      return {t, t};
    }
    int ma = -1e18, mi = 1e18;
    for (int i = 0; i < n; ++i) {
      if (b[i] == 0 || a[i] == 0) {
        continue;
      }
      if (cur & 1) {
        auto ta = a;
        auto tb = b;
        ta[i] = 0;
        tb[i]--;
        auto res = dfs(cur + 1, ta, tb);
        ma = max(ma, res.first);
        mi = min(mi, res.second);
      } else {
        auto ta = a;
        auto tb = b;
        tb[i] = 0;
        ta[i]--;
        auto res = dfs(cur + 1, ta, tb);
        ma = max(ma, res.first);
        mi = min(mi, res.second);
      }
    }
    return {ma, mi};
  };
  for (int t = 0; t < n; ++t) {
    if (t & 1) {
      int mi = -1, mii = 1e18;
      for (int i = 0; i < n; ++i) {
        if (a[i] == 0 || b[i] == 0) {
          continue;
        }
        if (mi == -1) {
          mi = i;
          auto ta = a;
          auto tb = b;
          ta[i] = 0;
          tb[i]--;
          mii = dfs(t + 1, ta, tb).second;
        } else {
          auto ta = a;
          auto tb = b;
          ta[i] = 0;
          tb[i]--;
          int tmin = dfs(t + 1, ta, tb).second;
          if (tmin < mii) {
            mi = i;
            mii = tmin;
          }
        }
        if (mi == -1) {
          break;
        }
        a[mi] = 0;
        b[mi]--;
      }
    } else {
      int ma = -1, maa = -1e18;
      for (int i = 0; i < n; ++i) {
        if (a[i] == 0 || b[i] == 0) {
          continue;
        }
        if (ma == -1) {
          ma = i;
          auto ta = a;
          auto tb = b;
          tb[i] = 0;
          ta[i]--;
          maa = dfs(t + 1, ta, tb).first;
        } else {
          auto ta = a;
          auto tb = b;
          tb[i] = 0;
          ta[i]--;
          int tmax = dfs(t + 1, ta, tb).second;
          if (tmax > maa) {
            ma = i;
            maa = tmax;
          }
        }
        if (ma == -1) {
          break;
        }
        b[ma] = 0;
        a[ma]--;
      }
    }
  }
  cout << accumulate(a.begin(), a.end(), 0ll) -
              accumulate(b.begin(), b.end(), 0ll)
       << endl;
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
