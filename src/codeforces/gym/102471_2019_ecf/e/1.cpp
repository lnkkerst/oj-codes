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

#define int long long

using pii = pair<int, int>;

struct Node {
  int id;
  map<int, int>::iterator a;
};

void printQ(priority_queue<pii, vector<pii>, greater<pii>> q) {
  while (!q.empty()) {
    auto u = q.top();
    cout << u.first << ' ' << u.second << endl;
    q.pop();
  }
  cout << endl;
}

void solve() {
  int n, m;
  cin >> n >> m;
  deque<deque<pair<int, int>>> e(n + 1);
  int tot = 0;
  for (int i = 1; i <= m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    e[u].emplace_back(v, w);
    tot += w;
  }
  deque<deque<int>> a;
  for (auto [u, w] : e[1]) {
    deque<int> t;
    t.emplace_back(w);
    while (true) {
      if (e[u].empty()) {
        break;
      }
      t.emplace_back(e[u].front().second);
      u = e[u].front().first;
    }
    a.emplace_back(t);
  }
  int k = a.size();
  int len = a.front().size();
  int target = tot / len;
  deque<deque<pair<int, int>>> b(k);
  priority_queue<pii, vector<pii>, greater<pii>> q;
  int cur = 0;
  for (int i = 0; i < k; ++i) {
    map<int, int> t;
    for (auto j : a[i]) {
      // cout << j << ' ';
      ++t[j];
    }
    // cout << endl;
    for (auto j : t) {
      b[i].emplace_back(j);
    }
    q.push({b[i][0].second, i});
    cur += b[i][0].first;
  }
  int ans = 0;
  // cout << cur << ' ' << target << endl;
  while (cur < target) {
    // printQ(q);
    auto u = q.top();
    q.pop();
    int id = u.second;
    if (b[id].size() <= 1) {
      int inc = target - cur;
      ans += inc * b[id][0].second;
      cur += inc;
    } else {
      int inc = min(target - cur, b[id][1].first - b[id][0].first);
      ans += inc * b[id][0].second;
      b[id][1].second += b[id][0].second;
      b[id].pop_front();
      cur += inc;
      q.push({b[id][0].second, id});
    }
  }
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
