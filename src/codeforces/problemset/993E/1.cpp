#pragma GCC optimize(2)
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

#define int long long

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
  int n, x;
  cin >> n >> x;
  vector<int> a(n + 1);
  vector<int> r(n + 1), v(n + 1);
  r[0]++;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] = a[i] < x;
    a[i] += a[i - 1];
    r[a[i]]++;
  }
  for (int i = 0; i <= n; ++i) {
    v[n - i] = r[i];
  }
  auto fft = FFT();
  fft.read(r, v);
  auto ans = fft.mul();
  int ans0 = 0;
  for (int i = 0; i <= n; ++i) {
    if (r[i]) {
      ans0 += (r[i] * r[i] - r[i]) / 2;
    }
  }
  cout << ans0 << ' ';
  for (int i = 1; i <= n; ++i) {
    cout << ans[n + i] << ' ';
  }
  cout << endl;
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
