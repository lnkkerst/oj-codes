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
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < n; ++i) {
    if (s[i] != t[i]) {
      if (s[i] == '0' && t[i] == '1') {
        cout << "NO" << endl;
        return;
      }
      break;
    }
    if (s[i] == t[i] && t[i] == '1') {
      break;
    }
  }
  cout << "YES" << endl;
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
