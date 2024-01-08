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

constexpr double EPS = 1e-6;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  double tot = 0;
  for (auto &i : a) {
    cin >> i;
    tot += i;
  }
  double l = a[0], r = a[0] + 1;
  auto check = [&](double x) {
    double cur = 0;
    for (auto i : a) {
      cur += x;
      int h = cur;
      if (h != i) {
        if (h > i) {
          return 1;
        } else {
          return -1;
        }
      }
    }
    return 0;
  };
  for (int qwq = 1; qwq <= 100; ++qwq) {
    double x = (l + r) / 2;
    int res = check(x);
    if (res == 0) {
      l = x;
    } else if (res == 1) {
      r = x;
    } else {
      l = x;
    }
  }
  cout << fixed << setprecision(10) << l << endl;
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
