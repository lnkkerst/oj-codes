#pragma GCC optimize(2)
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  int ans = 0;
  int tot = 0;
  multiset<int> b;
  for (int i = 1; i <= n; ++i) {
    tot += i * i;
    b.insert(i * i);
  }
  for (int i = n; i >= 1; --i) {
    vector<int> a(n + 1);
    for (int j = 1; j < i; ++j) {
      a[j] = j;
    }
    for (int j = i; j <= n; ++j) {
      a[j] = n - (j - i);
    }
    int t = 0;
    int ma = 0;
    for (int j = 1; j <= n; ++j) {
      t += a[j] * j;
      ma = max(ma, a[j] * j);
    }
    t -= ma;
    ans = max(ans, t);
  }
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
