#pragma GCC optimize(2)
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(n);
  vector<pair<int, int>> b(n);
  vector<int> m(n);
  for (int i = 0; i < n; ++i) {
    cin >> m[i];
    for (int j = 0; j < m[i]; ++j) {
      int x;
      cin >> x;
      a[i].emplace_back(x);
    }
    sort(a[i].begin(), a[i].end());
    b[i].first = a[i][1];
    b[i].second = a[i][0];
  }
  sort(b.begin(), b.end());
  vector<int> c;
  int ans = 0;
  for (int i = n - 1; i >= 1; --i) {
    ans += b[i].first;
    c.emplace_back(b[i].second);
  }
  c.emplace_back(b[0].second);
  ans += *min_element(c.begin(), c.end());
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
