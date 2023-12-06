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

#define int long long

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  while (s.back() == 'A') {
    s.pop_back();
  }
  n = s.length();
  s = " " + s + " ";
  int cb = 0;
  int ans = 0;
  for (int i = n; i >= 1; --i) {
    if (s[i] == 'B') {
      ++cb;
    } else {
      ans += cb;
      cb = 1;
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
