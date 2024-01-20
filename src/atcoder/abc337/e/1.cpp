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
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  int m = 0;
  int x = n;
  while (x) {
    ++m;
    x >>= 1;
  }
  cout << m << endl;
  for (int i = 0; i < m; ++i) {
    cout << (1 << (m - 1)) << ' ';
    for (int j = 0; j < (1 << m); ++j) {
      if ((j >> i) & 1) {
        cout << j << ' ';
      }
    }
    cout << endl;
  }
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    if (s[i] == '1') {
      ans |= (1 << i);
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
