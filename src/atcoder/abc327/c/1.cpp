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
  int n = 9, m = 9;
  vector<vector<int>> a(n, vector<int>(m, 0));
  for (auto &i : a) {
    for (auto &j : i) {
      cin >> j;
    }
  }
  for (auto i : a) {
    set<int> s;
    for (auto j : i) {
      s.insert(j);
    }
    if (s.size() != 9) {
      cout << "No" << endl;
      return;
    }
  }
  for (int i = 0; i < 9; ++i) {
    set<int> s;
    for (int j = 0; j < 9; ++j) {
      s.insert(a[j][i]);
    }
    if (s.size() != 9) {
      cout << "No" << endl;
      return;
    }
  }
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      set<int> s;
      for (int k = 0; k < 3; ++k) {
        for (int l = 0; l < 3; ++l) {
          s.insert(a[i * 3 + k][j * 3 + l]);
        }
      }
      if (s.size() != 9) {
        cout << "No" << endl;
        return;
      }
    }
  }
  cout << "Yes" << endl;
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
