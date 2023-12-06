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
  int n, q;
  cin >> n >> q;
  vector<int> d(q);
  for (auto &i : d) {
    cin >> i;
  }
  vector<vector<int>> a(2);
  cout << "1 2" << endl;
  cout << "1 3" << endl;
  int last = 1;
  a[0].emplace_back(3);
  for (int i = 4; i <= n; ++i) {
    cout << last << ' ' << i << endl;
    last = i;
    a[1].emplace_back(i);
  }
  for (auto x : d) {
    if (x - 1 == a[0].size()) {
      cout << "-1 -1 -1" << endl;
      continue;
    } else if (x - 1 > a[0].size()) {
      vector<int> tmp;
      while (a[0].size() + tmp.size() != x - 1) {
        tmp.emplace_back(a[1].back());
        a[1].pop_back();
      }
      reverse(tmp.begin(), tmp.end());
      cout << tmp.front() << ' ';
      if (a[1].empty()) {
        cout << 1 << ' ';
      } else {
        cout << a[1].back() << ' ';
      }
      if (a[0].empty()) {
        cout << 1 << endl;
      } else {
        cout << a[0].back() << endl;
      }
      for (auto i : tmp) {
        a[0].emplace_back(i);
      }
    } else {
      vector<int> tmp;
      while (a[0].size() != x - 1) {
        tmp.emplace_back(a[0].back());
        a[0].pop_back();
      }
      reverse(tmp.begin(), tmp.end());
      cout << tmp.front() << ' ';
      if (a[0].empty()) {
        cout << 1 << ' ';
      } else {
        cout << a[0].back() << ' ';
      }
      if (a[1].empty()) {
        cout << 1 << endl;
      } else {
        cout << a[1].back() << endl;
      }
      for (auto i : tmp) {
        a[1].emplace_back(i);
      }
    }
  }
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
