#pragma GCC optimize(2)

#include <iostream>
#include <vector>

using namespace std;

#define int long long

int dis(char a, char b) {
  int x = a - '0';
  int y = b - '0';
  bool fl = 1;
  if (x > y) {
    swap(x, y);
    fl = 1;
  }
  return min(y - x, x + 10 - y) * fl;
}

void solve() {
  string s, t;
  cin >> s >> t;
  int n = s.length();
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = dis(s[i], t[i]);
  }
  int ans = 0;
  int last = 0;
  for (int i = 0; i < n; ++i) {}
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
