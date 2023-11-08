#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define int long long

void solve() {
  int n, k;
  vector<int> a;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    a.emplace_back(x);
  }
  sort(a.begin(), a.end());
  int ans = 0;
  int sm = 0;
  for (int i = 0; i < n; ++i) {
    sm += a[i];
    if (k - sm >= 0) {
      ans += max(0ll, (k - sm)) / (i + 1) + 1;
    }
  }
  cout << ans << endl;
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
