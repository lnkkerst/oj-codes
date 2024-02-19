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
  vector<int> a(4);
  vector<vector<int>> q(n, vector<int>(3));
  for (auto &i : q) {
    for (auto &j : i) {
      cin >> j;
    }
  }
  bool ans = false;
  for (a[1] = 1; a[1] <= 3 && !ans; ++a[1]) {
    for (a[2] = 1; a[2] <= 3 && !ans; ++a[2]) {
      for (a[3] = 1; a[3] <= 3 && !ans; ++a[3]) {
        vector<vector<int>> b(4, vector<int>(4));
        for (int i = 1; i <= 3; ++i) {
          for (int j = 1; j <= 3; ++j) {
            if (a[i] < a[j]) {
              b[i][j] = 1;
            } else {
              b[i][j] = 0;
            }
          }
        }
        bool fl = true;
        for (auto &i : q) {
          if (b[i[0]][i[1]] != i[2]) {
            fl = false;
          }
        }
        if (fl) {
          ans = true;
          break;
        }
      }
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
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
