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
  int n;
  cin >> n;
  vector<int> a(n);
  int g = 0;
  for (auto &i : a) {
    cin >> i;
    g ^= i;
  }
  unordered_map<int, int> s;
  bool fl = false;
  int mn = 60;
  auto insert = [&](int x) {
    for (int i = mn; i >= 0; --i) {
      if (x & (1ll << i)) {
        if (!s[i]) {
          s[i] = x;
          return;
        } else {
          x ^= s[i];
        }
      }
    }
    fl = true;
  };
  auto check = [&](int x) {
    for (int i = mn; i >= 0; --i) {
      if (x & (1ll << i)) {
        if (s.find(i) == s.end()) {
          return false;
        } else {
          x ^= s[i];
        }
      }
    }
    return true;
  };
  int ans = 0;
  for (auto i : a) {
    insert(i);
  }
  ans += qmi(2, n - s.size());
  for (auto i : a) {
    s.clear();
    unordered_set<int> b;
    int cnt = 0;
    for (int j = 1; j * j <= i; ++j) {
      if (i % j == 0) {
        b.insert(j);
        if (j * j != i) {
          b.insert(i / j);
        }
      }
    }
    for (auto i : b) {
      insert(i);
    }
    ans += qmi(2, b.size() - s.size());
    ans %= MOD;
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
