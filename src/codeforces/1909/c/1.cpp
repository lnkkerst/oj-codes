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
  vector<int> l(n), r(n), c(n);
  set<int> sl, sr;
  for (auto &i : l) {
    cin >> i;
    sl.insert(i);
  }
  for (auto &i : r) {
    cin >> i;
    sr.insert(i);
  }
  for (auto &i : c) {
    cin >> i;
  }
  sort(c.begin(), c.end(), greater<>());
  sort(l.begin(), l.end(), greater<>());
  sort(r.begin(), r.end());
  vector<int> a;
  for (auto x : l) {
    auto it = sr.lower_bound(x);
    a.emplace_back(*it - x);
    sr.erase(it);
  }
  sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += a[i] * c[i];
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
