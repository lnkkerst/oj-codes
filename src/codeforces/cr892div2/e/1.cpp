#pragma GCC optimize(2)

#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define int long long

using namespace std;

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
  vector<int> c;
  for (int i = 0; i < n; ++i) {
    c.emplace_back(abs(a[i] - b[i]));
  }
  sort(c.begin(), c.end(), greater<>());
  int ans = 0;
  for (int i = 0; i < k && i < n; ++i) {
    ans += c[i] * 2;
  }
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
