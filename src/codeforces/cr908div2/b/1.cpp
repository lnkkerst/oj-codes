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
  unordered_map<int, vector<int>> a;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    a[x].emplace_back(i);
  }
  if (a.size() < 2) {
    cout << -1 << endl;
    return;
  }
  vector<int> b(n + 1);
  int cnt = 0;
  for (auto &[k, v] : a) {
    if (v.size() >= 2) {
      if (!cnt) {
        for (int i = 0; i < v.size(); ++i) {
          if (i == 0) {
            b[v[i]] = 1;
          } else {
            b[v[i]] = 2;
          }
        }
      } else {
        for (int i = 0; i < v.size(); ++i) {
          if (i == 0) {
            b[v[i]] = 1;
          } else {
            b[v[i]] = 3;
          }
        }
      }
      ++cnt;
    } else {
      b[v[0]] = 1;
    }
  }
  if (cnt < 2) {
    cout << -1 << endl;
    return;
  }
  for (int i = 1; i <= n; ++i) {
    cout << b[i] << ' ';
  }
  cout << endl;
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
