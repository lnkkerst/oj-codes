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
  int k, n;
  cin >> k >> n;
  deque<int> a(n + 1);
  int ans = 0;
  set<deque<int>> b;
  function<void(int)> dfs = [&](int s) {
    if (s == n + 1) {
      bool fl = true;
      for (int i = 1; i <= n; ++i) {
        auto ta = a;
        for (int j = i; j <= n; ++j) {
          ta[j] = a[j - i + 1];
        }
        for (int j = 1; j < i; ++j) {
          ta[j] = a[n - i + j + 1];
        }
        if (b.find(ta) != b.end()) {
          fl = false;
          break;
        }
        ta.pop_front();
        reverse(ta.begin(), ta.end());
        ta.push_front(0);
        if (b.find(ta) != b.end()) {
          fl = false;
          break;
        }
      }
      if (fl) {
        ++ans;
        b.insert(a);
      }
      return;
    }
    for (int i = 1; i <= k; ++i) {
      a[s] = i;
      dfs(s + 1);
    }
    a[s] = 0;
  };
  dfs(1);
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
}
