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

struct Mat {
  int n, m;
  vector<vector<int>> dataee;
  Mat(int _n, int _m) {
    n = _n;
    m = _m;

    dataee = vector<vector<int>>(n + 1, vector<int>(m + 1));
  }
  vector<int> &operator[](int x) {
    return dataee[x];
  }
  Mat operator*(Mat b) {
    Mat c(n, b.m);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= b.m; ++j) {
        for (int k = 1; k <= m; ++k) {
          c[i][j] = (c[i][j] % MOD + dataee[i][k] * b[k][j] % MOD) % MOD;
        }
      }
    }
    return c;
  }
  Mat pow(int k) {
    Mat tmp(n, n), res(n, n);
    for (int i = 1; i <= n; res[i][i] = 1, ++i) {
      for (int j = 1; j <= n; ++j) {
        tmp[i][j] = dataee[i][j];
      }
    }
    while (k) {
      if (k & 1) {
        res = res * tmp;
      }
      tmp = tmp * tmp;
      k >>= 1;
    }
    return res;
  }
};

int qmi(int x, int k, int p = MOD) {
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

int inv(int x) {
  return qmi(x, MOD - 2, MOD);
}

int frac(int x, int y) {
  return x * inv(y) % MOD;
}

void solve() {
  int n;
  cin >> n;
  Mat v(2, 2);
  v[1][1] = v[1][2] = v[2][1] = 1;
  int x = v.pow(n - 1)[1][1] % MOD;
  cout << frac(x, qmi(2, n)) << endl;
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
