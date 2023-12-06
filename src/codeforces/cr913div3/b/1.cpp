#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <cctype>
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
  int cb = 0, cB = 0;
  reverse(s.begin(), s.end());
  string ans;
  for (auto i : s) {
    if (i == 'b') {
      ++cb;
    } else if (i == 'B') {
      ++cB;
    } else if (islower(i)) {
      if (cb) {
        --cb;
      } else {
        ans += i;
      }
    } else {
      if (cB) {
        --cB;
      } else {
        ans += i;
      }
    }
  }
  reverse(ans.begin(), ans.end());
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
