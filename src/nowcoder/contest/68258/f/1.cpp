#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <functional>
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

constexpr int MOD = 998244353;

int qmi(int x, int k, int p = MOD) {
  int res = 1;
  while (k) {
    if (k & 1) {
      res = (res * x) % p;
    }
    x = (x * x) % p;
    k >>= 1;
  }
  return res;
}

void solve() {
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  vector<vector<int>> a;
  vector<int> cur;
  function<void(int, int)> dfs = [&](int sp, int tp) {
    if (cur.size() == t.size()) {
      a.emplace_back(cur);
      return;
    }
    for (int i = sp; i < n; ++i) {
      if (s[i] == t[tp]) {
        cur.emplace_back(i);
        dfs(i + 1, tp + 1);
        cur.pop_back();
      }
    }
  };
  dfs(0, 0);
  int ans = 0;
  for (auto i : a) {
    for (auto j : i) {
      cout << j << ' ';
    }
    cout << endl;
    int tmp = 1;
    if (i.front() != 0) {
      tmp = (tmp * qmi(3, i.front() - 1)) % MOD;
    }
    for (int j = 0; j < i.size() - 1; ++j) {
      int len = i[j + 1] - i[j];
      if (len) {
        tmp = (tmp * qmi(3, len - 1)) % MOD;
      }
    }
    if (i.back() != n - 1) {
      tmp = (tmp * qmi(3, n - 1 - i.back() - 1)) % MOD;
    }
    ans = (ans + tmp) % MOD;
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
