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
  int n, k, d;
  cin >> n >> k >> d;
  vector<int> a(n + 1), b(k + 1);
  int c1 = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    c1 += a[i] == i;
  }
  for (int i = 1; i <= k; ++i) {
    cin >> b[i];
  }
  int cnt = 0;
  int cur = 1;
  int ans = c1 + (d - 1) / 2;
  for (int cnt = 1; cnt <= n * 3 && cnt <= d - 1; ++cnt) {
    int x = b[cur];
    ++cur;
    if (cur == k + 1) {
      cur = 1;
    }
    for (int i = 1; i <= x; ++i) {
      a[i]++;
    }
    int ct = 0;
    for (int i = 1; i <= n; ++i) {
      ct += a[i] == i;
    }
    ans = max(ans, ct + (d - cnt - 1) / 2);
  }
  cout << ans << endl;
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
