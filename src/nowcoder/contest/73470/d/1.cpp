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

#define int __int128_t

int gcd(int a, int b) {
  return !b ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
  return a * b / (gcd(a, b));
}

int qmi(int x, int k) {
  int res = 1;
  while (k) {
    if (k & 1) {
      res *= x;
    }
    x *= x;
    k >>= 1;
  }
  return res;
}

void solve() {
  long long x, y;
  cin >> x >> y;
  if (__gcd(x, y) == min(x, y)) {
    cout << 0 << endl;
    return;
  }
  vector<pair<int, pair<int, int>>> a;
  int g = __gcd(x, y);
  int bg = g;
  x /= g;
  y /= g;
  g = 1;
  if (x > y) {
    swap(x, y);
  }
  auto out = [&] {
    cout << a.size() << endl;
    for (auto [op, x] : a) {
      cout << (long long)op << ' ' << (long long)(x.first * bg) << ' '
           << (long long)(x.second * bg) << endl;
    }
    return;
  };
  a.emplace_back(1, make_pair(x, y));
  a.emplace_back(1, make_pair(x, y));
  int l = x * y;
  int ma = 1;
  while (ma < l && ma * 2 <= (int)1e18) {
    a.emplace_back(2, make_pair(ma, ma));
    a.emplace_back(2, make_pair(ma, ma));
    ma *= 2;
  }
  int cur = -1;
  int b = 0;
  while (l) {
    if (l & 1) {
      if (cur == -1) {
        cur = qmi(2, b);
      } else {
        a.emplace_back(2, make_pair(cur, qmi(2, b)));
        cur += qmi(2, b);
      }
    }
    ++b;
    l >>= 1;
  }
  out();
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
