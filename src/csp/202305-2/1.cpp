#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdlib>
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

struct Mat {
  vector<vector<int>> data;
  int n, m;
  Mat(int _n = 0, int _m = 0) : n(_n), m(_m) {
    data = vector<vector<int>>(n, vector<int>(m, 0));
  }
  Mat operator*(const Mat &b) const {
    Mat res(n, b.m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < b.m; ++j) {
        int tmp = 0;
        for (int k = 0; k < m; ++k) {
          tmp += data[i][k] * b.data[k][j];
        }
        res.data[i][j] = tmp;
      }
    }
    return res;
  }
  void read() {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> data[i][j];
      }
    }
  }
  void print() {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << data[i][j] << ' ';
      }
      cout << endl;
    }
  }
  Mat T() const {
    Mat res(m, n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        res.data[j][i] = data[i][j];
      }
    }
    return res;
  }
  Mat dotMulVector(const Mat &b) const {
    Mat res = *this;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        res.data[i][j] *= b.data.front()[i];
      }
    }
    return res;
  }
};

void solve() {
  int n, d;
  cin >> n >> d;
  Mat q(n, d);
  auto k = q, v = q;
  Mat w(1, n);
  q.read();
  k.read();
  v.read();
  w.read();
  ((q.dotMulVector(w) * (k.T() * v))).print();
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
