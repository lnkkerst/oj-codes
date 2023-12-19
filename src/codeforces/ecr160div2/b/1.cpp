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
  string s;
  cin >> s;
  int c0 = 0;
  int c1 = 0;
  for (auto &i : s) {
    c0 += i == '0';
    c1 += i == '1';
  }
  int ans = 0;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == '0') {
      if (c1) {
        --c1;
      } else {
        ans = s.length() - i;
        break;
      }
    } else {
      if (c0) {
        --c0;
      } else {
        ans = s.length() - i;
        break;
      }
    }
  }
  cout << ans << endl;
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
