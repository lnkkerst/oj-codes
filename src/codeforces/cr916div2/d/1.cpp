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
  vector<pair<int, int>> a(n), b(n), c(n);
  for (auto &i : a) {
    cin >> i.first;
  }
  for (int i = 0; i < n; ++i) {
    a[i].second = i;
  }
  for (auto &i : b) {
    cin >> i.first;
  }
  for (int i = 0; i < n; ++i) {
    b[i].second = i;
  }
  for (auto &i : c) {
    cin >> i.first;
  }
  for (int i = 0; i < n; ++i) {
    c[i].second = i;
  }
  sort(a.begin(), a.end(), greater<>());
  sort(b.begin(), b.end(), greater<>());
  sort(c.begin(), c.end(), greater<>());
  int ans = 0;
  for (int i = 0; i < min(10ll, n); ++i) {
    for (int j = 0; j < min(10ll, n); ++j) {
      for (int k = 0; k < min(10ll, n); ++k) {
        if ((a[i].second == b[j].second) + (a[i].second == c[k].second)
              + (b[j].second == c[k].second)
            != 0) {
          continue;
        }
        ans = max(ans, a[i].first + b[j].first + c[k].first);
      }
    }
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
