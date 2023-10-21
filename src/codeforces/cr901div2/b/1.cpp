#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define int long long

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  vector<int> b(m);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &i : b) {
    cin >> i;
  }
  k = !(k % 2) + 1;
  for (int i = 1; i <= k; ++i) {
    if (i & 1) {
      auto &mi = *min_element(a.begin(), a.end());
      auto &ma = *max_element(b.begin(), b.end());
      if (mi < ma) {
        swap(mi, ma);
      }
    } else {
      auto &mi = *min_element(b.begin(), b.end());
      auto &ma = *max_element(a.begin(), a.end());
      if (mi < ma) {
        swap(mi, ma);
      }
    }
  }
  cout << accumulate(a.begin(), a.end(), 0) << endl;
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
