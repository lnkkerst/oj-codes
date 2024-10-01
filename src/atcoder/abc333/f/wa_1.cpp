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
using pii = pair<int, int>;

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

int inv(int x) {
  return qmi(x, MOD - 2, MOD);
}

void solve() {
  int n;
  cin >> n;
  vector<pii> a{
    {},
    {1, 3},
    {2, 3}
  };
  for (int i = 3; i <= n; ++i) {
    vector<pii> mu(i);
    mu[0] = {1, 1};
    for (int j = 1; j <= i - 1; ++j) {
      mu[j] = mu[j - 1];
      mu[j].first *= a[i - j].first;
      mu[j].second *= a[i - j].second * 2;
      mu[j].first %= MOD;
      mu[j].second %= MOD;
      cout << "mu " << j << ' ' << mu[j].first << ' ' << mu[j].second << endl;
    }
    vector<pii> na{{}};
    for (int j = 1; j <= i; ++j) {
      int cx1 = 1, cy1 = 1;
      cx1 *= mu[i - j].first;
      cy1 *= mu[i - j].second;
      cx1 %= MOD;
      cy1 %= MOD;
      cy1 *= qmi(2, j);
      cx1 %= MOD;
      cy1 %= MOD;
      int cx2 = 1, cy2 = 1;
      cx2 *= mu[i - 1].first;
      cy2 *= mu[i - 1].second;
      cx2 %= MOD;
      cy2 %= MOD;
      cx2 *= mu[i - j].second;
      cy2 *= mu[i - j].first;
      cx2 %= MOD;
      cy2 %= MOD;
      cx2 *= qmi(2, i - j);
      cx2 %= MOD;

      int cy = cy1 * cy2;
      int cx = cx1 * cx2;
      cx %= MOD;
      cy %= MOD;

      cout << "cxy1 " << cx1 << ' ' << cy1 << endl;
      cout << "cxy2 " << cx2 << ' ' << cy2 << endl;
      cout << "cxy " << cx << ' ' << cy << endl;

      int dy = qmi(2, i);
      int dx = (dy - 1 + MOD) % MOD;
      swap(dy, dx);
      int ny = cy * dy;
      int nx = cx * dx;
      ny %= MOD;
      nx %= MOD;
      na.emplace_back(nx, ny);
    }
    a = na;
  }
  for (int i = 1; i <= n; ++i) {
    cout << a[i].first * inv(a[i].second) % MOD << ' ';
  }
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
