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
  s = s.substr(2);
  int x = stoi(s);
  int t = (x + 1) / 2;
  int cr = 0, cp = 0;
  int ans = 0;
  string ass = "to be continued.";
  cin >> s;
  for (auto i : s) {
    ++ans;
    if (i == 'R') {
      ++cr;
    } else {
      ++cp;
    }
    if (cr == t || cp == t) {
      if (cr == t) {
        ass = "kou!";
      } else {
        ass = "yukari!";
      }
      break;
    }
  }
  cout << ass << endl << ans << endl;
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
