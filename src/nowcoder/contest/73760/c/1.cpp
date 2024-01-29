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
  auto bs = s;
  int n = s.length();
  for (int i = 1; i < n / 2; ++i) {
    if (s[i] != s[i - 1]) {
      swap(s[i], s[i - 1]);
      swap(s[n - i - 1], s[n - i]);
      break;
    }
  }
  if (s == bs) {
    cout << -1 << endl;
  } else {
    cout << s << endl;
  }
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
