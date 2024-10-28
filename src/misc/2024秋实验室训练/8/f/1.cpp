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

int qmi(int x, int k, int p) {
  int res = 1;
  while (k) {
    if (k & 1) {
      res *= x;
      res %= p;
    }
    x *= x;
    x %= p;
    k >>= 1;
  }
  return res;
}

struct StrHash {
  string s;
  vector<int> h;
  static constexpr int MOD = 998244353, BASE = 233;

  StrHash() = default;
  StrHash(const string &_s) {
    s = _s;
    calc_hash(0, s.length() - 1);
  }
  void calc_hash(int l = 0, int r = -1) {
    if (r == -1) {
      r = s.size() - 1;
    }
    if (h.size() <= r) {
      h.resize(r + 1);
    }
    if (l == 0) {
      h[l] = s[l];
      ++l;
    }
    for (int i = l; i <= r; ++i) {
      h[i] = h[i - 1] + s[i] * qmi(BASE, i, MOD) % MOD;
      h[i] %= MOD;
    }
  }
  int get_hash(int l = 0, int r = -1) {
    if (r == -1) {
      r = s.size() - 1;
    }
    if (l == 0) {
      return h[r];
    }
    return ((h[r] - h[l - 1]) % MOD + MOD) % MOD
           * qmi(qmi(BASE, l, MOD), MOD - 2, MOD) % MOD;
  }
};

void solve() {
  int n;
  cin >> n;
  StrHash ans;
  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    StrHash h(s);
    int mx = -1;
    for (int j = 0; j < s.size() && j < ans.s.size(); ++j) {
      if (ans.get_hash(ans.s.size() - j - 1) == h.get_hash(0, j)) {
        mx = j;
      }
    }
    ans.s += s.substr(mx + 1);
    ans.calc_hash(max(0ll, (int)(ans.s.size() - s.size())));
  }
  cout << ans.s << endl;
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
