#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define int long long

void solve() {
  string s;
  cin >> s;
  s += s;
  int ma = 0;
  int cur = 0;
  int su = 0;
  for (auto i : s) {
    if (i == '0') {
      ma = max(ma, cur);
      cur = 0;
    }
    if (i == '1') {
      ++cur;
    }
    su += i == '1';
  }
  ma = max(ma, cur);
  if (su == s.size()) {
    cout << (su / 2) * (su / 2) << endl;
    return;
  }
  cout << (ma + 1) / 2 * ((ma + 1 + (ma % 2 == 0)) / 2) << endl;
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
