#pragma GCC optimize(2)

#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define int long long

void solve() {
  string n;
  int s;
  cin >> n >> s;
  vector<int> a;
  int tot = 0;
  for (auto i : n) {
    a.emplace_back(i - '0');
    tot += a.back();
  }
  reverse(a.begin(), a.end());
  if (tot <= s) {
    cout << 0 << endl;
    return;
  }
  int last = 0, base = 0;
  int ans = 0;
  for (int i = 0; i < a.size(); ++i) {
    // for (auto i : a) {
    //   cout << i << ' ';
    // }
    // cout << endl;
    // cout << ans << ' ' << tot << endl;
    if (base == 0) {
      base = 1;
    } else {
      base *= 10;
    }
    int oa = a[i];
    a[i] += last;
    last = a[i] / 10;
    a[i] %= 10;
    tot -= (oa - a[i]);
    if (tot + last <= s) {
      cout << ans << endl;
      return;
    }
    if (a[i] == 0) {
      continue;
    }
    tot -= a[i];
    ans += (10 - a[i]) * base;
    last = 1;
    a[i] = 0;
  }
  base *= 10;
  int oa = 0;
  int x = last;
  tot += x;
  cout << ans << endl;
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
