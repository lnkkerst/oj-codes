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
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  if (n % 2 == 0) {
    int l = 0, r = 2e12;
    for (int qwq = 1; qwq <= 50; ++qwq) {
      int mid = (l + r) / 2;
      bool fl = true;
      for (int i = 2; i <= n; ++i) {
        if (a[i] + mid < a[i - 1]) {
          fl = false;
          break;
        }
      }
      if (fl) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    cout << r << endl;
    return;
  }
  if (n == 1) {
    cout << 0 << endl;
    return;
  }
  if (a[n] < a[n - 1]) {
    cout << -1 << endl;
    return;
  }
  auto check = [=]() {
    auto get_max = [&](int x, int cur) {
      return (a[x + 1] + cur - a[x]) / x;
    };
    int tot = 0;
    for (int i = n - 1; i >= 2; i -= 2) {
      if (a[i + 1] + tot < a[i]) {
        return false;
      }
      tot += get_max(i, tot);
      if ((a[i] + tot < a[i - 1]) || (a[i - 1] + tot < a[i - 2])) {
        return false;
      }
    }
    return true;
  };
  if (!check()) {
    cout << -1 << endl;
    return;
  }
  int l = 0, r = 2e12;
  auto get_max = [&](int x, int cur) {
    return (a[x + 1] + cur - a[x]) / x;
  };
  for (int qwq = 1; qwq <= 50; ++qwq) {
    int mid = (l + r) / 2;
    bool fl = true;
    int tot = 0;
    for (int i = n - 1; i >= 2; i -= 2) {
      if (a[i + 1] + tot < a[i]) {
        fl = false;
        break;
      }
      int t = tot + get_max(i, tot);
      tot = max(tot, mid);
      if ((a[i] + tot < a[i - 1]) || (a[i - 1] + tot < a[i - 2])) {
        fl = false;
        break;
      }
    }
    if (fl) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << r << endl;
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
