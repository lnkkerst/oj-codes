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

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  auto check1 = [&]() -> int {
    int cur = m;
    int res = 0;
    for (int i = 1; i <= n; ++i) {
      if (a[i] == 0) {
        res += m - cur;
        cur = m;
      } else {
        cur -= a[i];
      }
      if (cur <= 0) {
        return -1;
      }
    }
    return res;
  };
  auto ma = check1();
  if (ma == -1) {
    cout << "NO" << endl;
    return;
  }
  vector<int> c;
  int cur = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == 0) {
      if (cur) {
        c.emplace_back(cur);
        cur = 0;
      }
    } else {
      cur += a[i];
    }
  }
  if (cur) {
    c.emplace_back(cur);
  }
  cur = 0;
  reverse(c.begin(), c.end());
  int des = 0;
  for (auto i : c) {
    if (des + i >= m) {
      break;
    }
    des += i;
  }
  int tot = 0;
  for (auto i : c) {
    tot += i;
  }
  cout << tot - des + n - 1 << endl;
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
