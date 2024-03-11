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
  vector<int> a(n + 2);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << a[1] - 1 << endl;
    return;
  }
  auto calc = [&](vector<int> a) {
    int tot = 0;
    tot += a[1] - 1;
    tot += a[n] - 1;
    a[1] = 1;
    a[n] = 1;
    for (int i = 2; i <= n; ++i) {
      int x = min(a[i - 1], a[i]) - 1;
      tot += x;
      a[i] -= x;
      a[i - 1] -= x;
    }
    return tot;
  };
  int ans = calc(a);
  reverse(a.begin(), a.end());
  ans = max(ans, calc(a));
  cout << ans << endl;
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
