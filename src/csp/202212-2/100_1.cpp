#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> ans1(m + 1), ans2(m + 1);
  auto pre = ans1;
  auto cost = ans1;
  vector<vector<int>> after(m + 1);
  for (int i = 1; i <= m; ++i) {
    int x;
    cin >> x;
    pre[i] = x;
    after[x].emplace_back(i);
  }
  for (int i = 1; i <= m; ++i) {
    cin >> cost[i];
  }
  function<int(int)> getCost = [&](int x) -> int {
    if (x == 0) {
      return 0;
    }
    if (ans1[x] != 0) {
      return ans1[x];
    }
    ans1[x] = getCost(pre[x]) + cost[x];
    return ans1[x];
  };
  bool fl = true;
  for (int i = 1; i <= m; ++i) {
    cout << getCost(pre[i]) + 1 << ' ';
    if (getCost(i) > n) {
      fl = false;
    }
  }
  cout << endl;
  if (!fl) {
    return;
  }
  function<void(int, int)> dfs = [&](int cur, int last) -> void {
    if (cur == 0) {
      return;
    }
    last += cost[cur];
    ans2[cur] = max(ans2[cur], last);
    dfs(pre[cur], last);
  };
  for (int i = m; i >= 1; --i) {
    dfs(i, 0);
  }
  for (int i = 1; i <= m; ++i) {
    cout << n - ans2[i] + 1 << ' ';
  }
  cout << endl;
}

int main() {
  int t;
  // cin >> t;
  t = 1;
  while (t--) {
    solve();
  }
}
