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

inline constexpr int MOD = 998244353;

int qmi(int x, int k, int p = MOD) {
  int res = 1;
  while (k) {
    if (k & 1) {
      res = res * x % p;
    }
    x = x * x % p;
    k >>= 1;
  }
  return res;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<int> mi(n + 1), ma(n + 1);
  auto mic = mi, mac = ma;
  mic[0] = 1;
  mac[0] = 1;
  for (int i = 1; i <= n; ++i) {
    if (a[i] >= 0) {
      mi[i] = mi[i - 1] + a[i];
      ma[i] = abs(ma[i - 1] + a[i]);
      mic[i] = mic[i - 1];
      if (mi[i] >= 0) {
        mic[i] += mic[i - 1];
      }
      mac[i] = mac[i - 1];
      if (ma[i - 1] + a[i] >= 0) {
        mac[i] += mac[i - 1];
      }
    } else {
      mi[i] = mi[i - 1] + a[i];
      mic[i] = mic[i - 1];
      if (mi[i] >= 0) {
        mic[i] += mic[i - 1];
      }
      ma[i] = max(abs(mi[i - 1] + a[i]), abs(ma[i - 1] + a[i]));
      if (ma[i - 1] != mi[i - 1]) {
        if (abs(mi[i - 1] + a[i]) == ma[i]) {
          mac[i] += mic[i - 1];
        }
        if (abs(ma[i - 1] + a[i]) == ma[i]) {
          mac[i] += mac[i - 1];
        }
        if ((mi[i - 1] + a[i]) == ma[i]) {
          mac[i] += mic[i - 1];
        }
        if ((ma[i - 1] + a[i]) == ma[i]) {
          mac[i] += mac[i - 1];
        }
      } else {
        mac[i] += mac[i - 1];
      }
    }
    mic[i] %= MOD;
    mac[i] %= MOD;
    // cout << mi[i] << ' ' << ma[i] << endl;
    // cout << mic[i] << ' ' << mac[i] << endl;
  }
  // cout << ma[n] << endl;
  cout << mac[n] << endl;
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
