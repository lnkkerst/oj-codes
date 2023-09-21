
#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bits/extc++.h>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
using namespace __gnu_pbds;

#define int long long

void solve() {
  int n, k;
  cin >> n >> k;
  map<int, int> fc, lc;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    if (!fc[x]) {
      fc[x] = i;
    }
    lc[x] = i;
  }
  int l = n, r = 1;
  map<int, int> ans;
  for (int i = k; i >= 1; --i) {
    if (!lc[i]) {
      continue;
    }
    l = min(l, fc[i]);
    r = max(r, lc[i]);
    ans[i] = (r - l + 1) * 2;
  }
  for (int i = 1; i <= k; ++i) {
    cout << ans[i] << ' ';
  }
  cout << endl;
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
