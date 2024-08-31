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
  int b, d;
  string a, c;
  cin >> b >> d >> a >> c;
  int la = a.length();
  int lc = c.length();
  vector<int> cnt(lc);
  for (int i = 0; i < lc; ++i) {
    int pos = i;
    for (int j = 0; j < la; ++j) {
      if (a[j] == c[pos]) {
        ++pos;
        ++cnt[i];
        if (pos >= c.length()) {
          pos = 0;
        }
      }
    }
  }
  int tot = 0;
  int pos = 0;
  for (int i = 1; i <= b; ++i) {
    tot += (pos + cnt[pos]) / lc;
    pos = (pos + cnt[pos]) % lc;
  }
  cout << tot / d << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
