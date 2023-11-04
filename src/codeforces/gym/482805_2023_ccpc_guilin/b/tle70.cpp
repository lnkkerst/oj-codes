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
  int cnt = 0;
  deque<int> ans;
  while (dif - cnt > tot) {
    int x = a.front();
    a.pop_front();
    ans.emplace_back(x);
    ++x;
    auto it = lower_bound(a.begin(), a.end(), x);
    a.insert(it, x);
    it = lower_bound(a.begin(), a.end(), x);
    int index = it - a.begin();
    for (auto i : a) {
      cout << i << ' ';
    }
    cout << endl;
    cout << x << ' ' << index << endl;
    cout << dif << ' ' << cnt << ' ' << tot << ' ' << a.size() << endl;
    if (index >= a.size() - m) {
      --tot;
    }
    a.pop_front();
    ++cnt;
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
