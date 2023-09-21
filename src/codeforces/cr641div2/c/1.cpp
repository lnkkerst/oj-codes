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

#define int long long

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * b / gcd(a, b); }

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end());
  vector<int> pre = a;
  vector<int> suf = a;
  for (int i = 1; i < n; ++i) {
    pre[i] = gcd(pre[i - 1], pre[i]);
  }
  for (int i = n - 2; i >= 0; --i) {
    suf[i] = gcd(suf[i + 1], suf[i]);
  }
  int ans = lcm(suf[1], pre[n - 2]);
  for (int i = 1; i < n - 1; ++i) {
    ans = lcm(ans, gcd(pre[i - 1], suf[i + 1]));
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
