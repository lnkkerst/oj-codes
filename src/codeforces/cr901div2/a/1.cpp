#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define int long long

void solve() {
  int a, b, n;
  cin >> a >> b >> n;
  int ans = b;
  vector<int> c(n);
  for (auto &i : c) {
    cin >> i;
    ans += min(i, a - 1);
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
