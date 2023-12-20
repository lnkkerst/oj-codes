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
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &i : b) {
    cin >> i;
  }
  int ma = b[0];
  int tot = a[0];
  int cnt = 1;
  int ans = tot + ma * (k - cnt);
  for (int i = 1; i < n; ++i) {
    ++cnt;
    if (cnt > k) {
      break;
    }
    ma = max(ma, b[i]);
    tot += a[i];
    ans = max(ans, tot + (k - cnt) * ma);
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
