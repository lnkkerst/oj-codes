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

constexpr int MOD = 998244353;

void solve() {
  int n;
  cin >> n;
  vector<int> f(n * 10);
  auto getId = [&](int x, char c) {
    return (x - 1) * 5 + c - 'A' + 1;
  };
  for (int i = 1; i <= n * 6; ++i) {
    f[i] = i;
  }

  function<int(int)> find = [&](int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
  };
  auto merge = [&](int x, int y) {
    f[find(x)] = find(y);
  };

  for (int i = 1; i <= n; ++i) {
    int id;
    cin >> id;
    string s;
    cin >> s;
    for (int j = 0; j < 5; ++j) {
      int u = getId(i, 'A' + j);
      int v = getId(id, s[j]);
      merge(u, v);
    }
  }
  map<int, set<int>> b;
  map<int, int> ba;
  for (int i = 1; i <= n * 5; ++i) {
    b[find(i)].insert(i / 5);
    ++ba[find(i)];
  }
  int ans = 0;
  for (auto i : b) {
    if (i.second.size() == n && ba[i.first] == n) {
      ++ans;
    }
  }
  cout << ans % MOD << endl;
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
