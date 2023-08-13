#pragma GCC optimize(2)
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());

  int l = 0, r = n - 1, sz = n;
  while (l <= r) {
    if ((a[r].first == n - l) ^ (a[l].first == n - 1 - r)) {
      if (a[r].first == n - l) {
        ans[a[r].second] = sz;
        --r;
      } else {
        ans[a[l].second] = -sz;
        ++l;
      }
      --sz;
    } else {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
  for (auto i : ans) {
    cout << i << ' ';
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
