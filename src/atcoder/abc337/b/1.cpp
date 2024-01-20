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
  int n = s.length();
  string t;
  t += s[0];
  for (int i = 1; i < n; ++i) {
    if (t.back() == s[i]) {
      continue;
    }
    t += s[i];
  }
  n = t.size();
  for (int i = 1; i < n; ++i) {
    if (t[i] < t[i - 1]) {
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
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
