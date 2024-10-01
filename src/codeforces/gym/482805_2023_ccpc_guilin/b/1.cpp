#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bits/extc++.h>
#include <bitset>
#include <deque>
#include <ext/rope>
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
using namespace __gnu_pbds;
using namespace __gnu_cxx;

void solve() {
  int n, m;
  cin >> n >> m;
  int dif = n - m;
  deque<int> a(n), b(m);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &j : b) {
    cin >> j;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int tot = 0;
  for (int i = 1; i <= m; ++i) {
    if (a[a.size() - i] > b[b.size() - i]) {
      cout << -1 << endl;
      return;
    }
    tot += b[b.size() - i] - a[a.size() - i];
  }
  if (tot > dif) {
    cout << -1 << endl;
    return;
  }
  tree<int, null_type, less_equal<>, rb_tree_tag,
       tree_order_statistics_node_update>
    sa;
  rope<int> ra;
  for (auto i : a) {
    sa.insert(i);
  }
  int cnt = 0;
  deque<int> ans;
  while (!sa.empty() && dif - cnt > tot) {
    int x = *sa.begin();
    sa.erase(sa.begin());
    ans.emplace_back(x);
    ++x;
    sa.insert(x);
    int index = sa.order_of_key(x);
    if (index >= sa.size() - m) {
      --tot;
    }
    sa.erase(sa.begin());
    ++cnt;
  }
  a = deque<int>{sa.begin(), sa.end()};
  if (a.size() < b.size()) {
    cout << -1 << endl;
    return;
  }
  for (int i = 1; i <= m; ++i) {
    if (a[a.size() - i] > b[b.size() - i]) {
      cout << -1 << endl;
      return;
    }
    while (a[a.size() - i] < b[b.size() - i]) {
      ans.emplace_back(a[a.size() - i]);
      a[a.size() - i]++;
      a.pop_front();
    }
  }
  cout << ans.size() << endl;
  for (auto i : ans) {
    cout << i << ' ';
  }
  cout << endl;
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
