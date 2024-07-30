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
  vector<vector<char>> a(9, vector<char>(9));
  int tx = -1, ty = -1;
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      cin >> a[i][j];
      if (tx == -1 && a[i][j] == '8') {
        if (i > 0 && i < 8 && j > 0 && j < 8) {
          tx = i;
          ty = j;
        }
      }
    }
  }
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      if (i == tx && j == ty) {
        continue;
      }
      a[i][j] = -1;
    }
  }
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      if (a[i][j] == -1) {
        cout << '*';
      } else {
        cout << a[i][j];
      }
    }
    cout << endl;
  }
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
