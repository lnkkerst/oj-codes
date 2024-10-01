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
  int n, m;
  cin >> n >> m;
  auto process_7 = [&](int x) {
    vector<int> res;
    while (x) {
      res.push_back(x % 7);
      x /= 7;
    }
    reverse(res.begin(), res.end());
    if (res.empty()) {
      res.emplace_back(0);
    }
    return res;
  };
  auto process_10 = [&](vector<int> a) {};
  auto n7 = process_7(n - 1);
  auto m7 = process_7(m - 1);
  int len = n7.size() + m7.size();
  if (n == 1 && m == 1) {
    cout << 0 << endl;
    return;
  }
  if (len > 7) {
    cout << 0 << endl;
    return;
  }
  vector<int> cur(len);
  set<int> s;
  int ans = 0;
  function<void(int)> dfs = [&](int step) {
    if (step == len) {
      auto cn7 = vector<int>{cur.begin(), cur.begin() + n7.size()};
      auto cm7 = vector<int>{cur.begin() + n7.size(), cur.end()};
      if (cn7 <= n7 && cm7 <= m7) {

        ++ans;
      }
      return;
    }
    for (int i = 0; i < 7; ++i) {
      if (s.find(i) == s.end()) {
        s.insert(i);
        cur[step] = i;
        dfs(step + 1);
        s.erase(i);
      }
    }
  };
  dfs(0);
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
