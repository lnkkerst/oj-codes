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
  for (int i = 1; i < n; ++i) {
    string a = s.substr(0, i);
    string b = s.substr(i);
    if (a[0] == '0' || b[0] == '0') {
      continue;
    }
    int xa = stoi(a);
    int xb = stoi(b);
    if (xa && xb && xa < xb) {

      cout << xa << ' ' << xb << endl;
      return;
    }
  }
  cout << -1 << endl;
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
