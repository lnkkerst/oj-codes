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
  int n = 3;
  vector<vector<char>> a(3, vector<char>(3));
  int x = 0, y = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
      if (a[i][j] == '?') {
        x = i;
        y = j;
      }
    }
  }
  auto check = [&]() {
    for (int i = 0; i < n; ++i) {
      set<int> b;
      for (int j = 0; j < n; ++j) {
        b.insert(a[i][j]);
      }
      if (b.size() != 3) {
        return false;
      }
    }
    for (int i = 0; i < n; ++i) {
      set<int> b;
      for (int j = 0; j < n; ++j) {
        b.insert(a[j][i]);
      }
      if (b.size() != 3) {
        return false;
      }
    }
    return true;
  };
  for (char i = 'A'; i <= 'C'; ++i) {
    a[x][y] = i;
    if (check()) {
      cout << i << endl;
      return;
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
