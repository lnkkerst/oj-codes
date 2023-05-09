#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define int long long

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  for (auto &i : a) {
    cin >> i.first;
  }
  for (auto &i : a) {
    cin >> i.second;
  }
  {
    int tmp = 0;
    for (auto &i : a) {
      tmp += i.second - i.first + 1;
    }
    if (tmp < k) {
      cout << -1 << endl;
      return;
    }
  }
  sort(a.begin(), a.end(), [](pair<int, int> &a, pair<int, int> &b) -> bool {
    return a.first < b.first;
  });
  int l = 1, r = 2e18;
  while (l < r) {
    int mid = (l + r) / 2;
    auto it = lower_bound(a.begin(), a.end(), make_pair(mid, mid));
  }
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
