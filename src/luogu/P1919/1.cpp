#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <complex>
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

// 看不懂，当黑盒
struct FFT {
  vector<complex<double>> f;
  vector<int> rev;
  int limit = 1;
  int l = -1;
  int n, m, t;
  auto read(const vector<int> &a, const vector<int> &b) {
    n = a.size() - 1;
    m = b.size() - 1;
    t = n + m;
    n = max(n, m);
    limit = 1, l = -1;
    while (limit <= (n << 1)) {
      limit <<= 1;
      ++l;
    }
    rev.clear();
    rev.resize(limit + 1);
    for (int i = 1; i <= limit; ++i) {
      rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << l);
    }
    f.clear();
    f.resize(limit + 1);
    for (int i = 0; i < a.size(); ++i) {
      f[i].real(a[i]);
    }
    for (int i = 0; i < b.size(); ++i) {
      f[i].imag(b[i]);
    }
  }

  void fft(int type, int limit) {
    for (int i = 1; i <= limit; ++i) {
      if (i >= rev[i]) {
        continue;
      }
      swap(f[i], f[rev[i]]);
    }
    complex<double> rt, w, x, y;
    double pi = acos(-1);
    for (int mid = 1; mid < limit; mid <<= 1) {
      int r = mid << 1;
      rt = complex<double>(cos(pi / mid), type * sin(pi / mid));
      for (int j = 0; j < limit; j += r) {
        w = complex<double>(1, 0);
        for (int k = 0; k < mid; ++k) {
          x = f[j | k];
          y = w * f[j | k | mid];
          f[j | k] = x + y;
          f[j | k | mid] = x - y;
          w = w * rt;
        }
      }
    }
    if (type == 1) {
      return;
    }
    for (int i = 0; i <= limit; ++i) {
      f[i].imag(f[i].imag() / limit);
      f[i].real(f[i].real() / limit);
    }
  }

  auto mul() {
    fft(1, limit);
    for (int i = 0; i <= limit; ++i) {
      f[i] = f[i] * f[i];
    }
    fft(-1, limit);
    vector<int> c(t + 1);
    for (int i = 0; i <= t; ++i) {
      c[i] = f[i].imag() / 2 + 0.5;
    }
    return c;
  }
};

void solve() {
  string sa, sb;
  cin >> sa >> sb;
  int n = sa.length(), m = sb.length();
  vector<int> a(n), b(m);
  for (int i = 0; i < n; ++i) {
    a[i] = sa[i] - '0';
  }
  for (int i = 0; i < m; ++i) {
    b[i] = sb[i] - '0';
  }
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  auto fft = FFT();
  fft.read(a, b);
  auto c = fft.mul();
  for (int i = 0; i < c.size() - 1; ++i) {
    c[i + 1] += c[i] / 10;
    c[i] %= 10;
  }
  if (c.back() / 10) {
    int t = c.back() / 10;
    c.back() %= 10;
    c.emplace_back(t);
  }
  reverse(c.begin(), c.end());
  for (auto i : c) {
    cout << i;
  }
  cout << endl;
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
