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

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  deque<int> a(n);
  vector<int> b(m);
  vector<int> vis(n + 1);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &i : b) {
    cin >> i;
  }
  for (int i = 0; i < m; ++i) {
    if (vis[b[i]]) {
      continue;
    }
    if (a.front() == b[i]) {
      a.pop_front();
      vis[b[i]] = true;
      continue;
    }
    cout << "TIDAK" << endl;
    return;
  }
  cout << "YA" << endl;
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
