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

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n), b(n);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &i : b) {
    cin >> i;
  }
  vector<pair<int, int>> pos;
  for (int i = 0; i < n; ++i) {
    pos.emplace_back(a[i], i);
  }
  sort(pos.begin(), pos.end());
  sort(b.begin(), b.end());
  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    ans[pos[i].second] = b[(i + x) % n];
  }
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    cnt += a[i] > ans[i];
  }
  if (cnt != x) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  for (auto i : ans) {
    cout << i << ' ';
  }
  cout << endl;
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
