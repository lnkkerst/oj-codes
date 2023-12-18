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
  int n;
  cin >> n;
  deque<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  for (int k = 0; k < n; ++k) {
    set<int> s;
    for (int i = 0; i <= n; ++i) {
      s.insert(i);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      s.erase(a[i]);
      ans += *s.begin();
    }
    cout << k << ' ' << ans << endl;
    auto t = a.front();
    a.pop_front();
    a.emplace_back(t);
  }
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
