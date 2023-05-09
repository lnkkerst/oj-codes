#include <algorithm>
#include <iostream>
#include <vector>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end());
  int ans = -2e18;
  ans = max(ans, a[0] * a[1]);
  ans = max(ans, a[a.size() - 1] * a[a.size() - 2]);
  if (find(a.begin(), a.end(), 0ll) != a.end()) {
    ans = max(ans, 0ll);
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
