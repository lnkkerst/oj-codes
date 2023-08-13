#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
#define int long long

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  deque<int> a(n);
  int tot = 0;
  for (auto &i : a) {
    cin >> i;
    tot += i;
  }
  sort(a.begin(), a.end());
  for (int i = a.size() - 1, j = 0; i >= 0 && j < k; --i, ++j) {
    tot -= a[i];
  }
  int il = 0, ir = a.size() - k - 1;
  int ans = tot;
  for (int t = 0; t < k; ++t) {
    ++ir;
    tot += a[ir];
    tot -= a[il];
    ++il;
    tot -= a[il];
    ++il;
    ans = max(ans, tot);
  }
  cout << ans << endl;
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
