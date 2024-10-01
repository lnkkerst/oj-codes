#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <functional>
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
  vector<int> a(n * 2);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end());
  vector<pair<int, int>> ans;
  for (int i = 0; i < n; ++i) {
    ans.emplace_back(a[i], a[n * 2 - i - 1]);
  }
  int ansd = 0;
  for (int i = 1; i < n; ++i) {
    ansd += abs(ans[i].first - ans[i - 1].first)
            + abs(ans[i].second - ans[i - 1].second);
  }
  cout << ansd << endl;
  for (auto [x, y] : ans) {
    cout << x << ' ' << y << endl;
  }
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
