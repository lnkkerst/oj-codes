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

vector<int> fib;
set<int> b;
map<int, vector<int>> mp;

void init() {
  fib = {0, 1};
  while (fib.back() <= 1e9) {
    fib.emplace_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
  }
  b = set<int>{fib.begin(), fib.end()};
  for (auto i : fib) {
    for (auto j : fib) {
      for (auto k : fib) {
        mp[i + j + k] = {i, j, k};
      }
    }
  }
}

void solve() {
  int n;
  cin >> n;
  if (!mp[n].empty()) {
    for (auto i : mp[n]) {
      cout << i << ' ';
    }
    cout << endl;
  } else {
    cout << -1 << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  init();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
