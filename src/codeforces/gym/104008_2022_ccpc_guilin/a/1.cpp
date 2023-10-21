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
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; ++i) {
    if (s[i] != '.') {
      continue;
    }
    if (i == 0 || s[i - 1] != 'L') {
      if (i == n - 1 || s[i + 1] != 'L') {
        s[i] = 'C';
      }
    }
  }
  cout << s << endl;
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
