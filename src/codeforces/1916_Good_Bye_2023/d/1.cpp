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
#define endl "\n"

void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
    return;
  }
  string s = "196";
  for (int i = 0; i < n - 3; ++i) {
    s += '0';
  }
  cout << s << endl;
  s = "169";
  for (int i = 0; i < n - 3; ++i) {
    s += '0';
  }
  int p6 = 1, p9 = 2;
  for (int i = 0; i < n / 2; ++i) {
    cout << s << endl;
    if (i != (n / 2) - 1) {
      swap(s[p9], s[p9 + 2]);
      swap(s[p6], s[p6 + 1]);
      p9 += 2;
      p6 += 1;
    }
  }
  s = "961";
  for (int i = 0; i < n - 3; ++i) {
    s += '0';
  }
  p6 = 2, p9 = 1;
  for (int i = 0; i < n / 2; ++i) {
    cout << s << endl;
    if (i != (n / 2) - 1) {
      swap(s[p6], s[p6 + 2]);
      swap(s[p9], s[p9 + 1]);
      p9 += 1;
      p6 += 2;
    }
  }
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
