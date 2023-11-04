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
  string s;
  cin >> s;
  int cnt = 0;
  for (auto i : s) {
    if (i == '(') {
      if (cnt < 0) {
        cnt = 0;
      }
      ++cnt;
    } else {
      --cnt;
    }
  }
  if (cnt > 0) {
    cout << "impossible" << endl;
    return;
  }
  cout << s << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
