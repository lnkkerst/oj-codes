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
    cout << "YES" << endl;
    return;
  }
  if (n == 1) {
    cout << "YES" << endl;
    return;
  }
  if (a[n] < a[n - 1]) {
    cout << "NO" << endl;
    return;
  }
  auto get_max = [&](int x, int cur) {
    return (a[x + 1] + cur - a[x]) / x;
  };
  auto add = [&](int l, int r, int x) {
    for (int i = l; i <= r; ++i) {
      a[i] += i * x;
    }
  };
  int tot = 0;
  for (int i = n - 1; i >= 2; i -= 2) {
    if (a[i + 1] + tot < a[i]) {
      cout << "NO" << endl;
      return;
    }
    tot += get_max(i, tot);
    if ((a[i] + tot < a[i - 1]) || (a[i - 1] + tot < a[i - 2])) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
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
