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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<string> a;
  function<void(string, int)> dfs = [&](string s, int step) {
    if (step >= n) {
      a.emplace_back(s);
      return;
    }
    if (s[step] == '?') {
      s[step] = '0';
      dfs(s, step + 1);
      s[step] = '1';
      dfs(s, step + 1);
    } else {
      dfs(s, step + 1);
    }
  };
  auto calc = [&](string s) {
    int res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        if (s[j] == '0') {
          break;
        }
        res += qmi(j - i + 1, k);
      }
    }
    return res;
  };
  dfs(s, 0);
  int ans = 0;
  for (auto s : a) {
    ans += calc(s);
  }
  cout << ans << endl;
  cout << ans * qmi(a.size(), MOD - 2) % MOD << endl;
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
