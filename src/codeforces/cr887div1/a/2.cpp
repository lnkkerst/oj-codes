// binary search solution
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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  for (int i = 0; i < n; ++i) {
    a[i] -= i;
  }
  int cur = 1;
  while (k--) {
    cur += upper_bound(a.begin(), a.end(), cur) - a.begin();
  }
  cout << cur << endl;
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
