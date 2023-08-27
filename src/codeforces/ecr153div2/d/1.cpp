#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  vector<int> c0(n), c1(n);
  int t01 = 0, t10 = 0;
  for (int i = 0; i < n; ++i) {
    int b0 = (i == 0) ? 0 : c0[i - 1];
    int b1 = (i == 0) ? 0 : c1[i - 1];
    c0[i] = b0 + (s[i] == '0');
    c1[i] = b1 + (s[i] == '1');
    if (s[i] == '0') {
      t10 += c1[i];
    } else {
      t01 += c0[i];
    }
  }
  cout << t01 << ' ' << t10 << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  // cin >> t;
  t = 1;
  while (t--) {
    solve();
  }
}
